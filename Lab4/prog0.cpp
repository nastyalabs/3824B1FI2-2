#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_PRODUCTS 100

typedef struct {
    char barcode[5]; 
    char name[50];
    int price;
    int discount;
} Product;

typedef struct {
    Product product;
    int quantity;
} ScannedProduct;

Product products[MAX_PRODUCTS];
int productCount = 0;
ScannedProduct scannedProducts[MAX_PRODUCTS];
int scannedCount = 0;

void addProduct(const char* barcode, const char* name, int price, int discount) {
    if (productCount >= MAX_PRODUCTS) {
        printf("Превышено максимальное количество товаров\n");
        return;
    }
    strcpy(products[productCount].barcode, barcode);
    strcpy(products[productCount].name, name);
    products[productCount].price = price;
    products[productCount].discount = discount;
    productCount++;
}

int findProductIndexByBarcode(const char* barcode) {
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].barcode, barcode) == 0) {
            return i;
        }
    }
    return -1;
}

void scanProduct() {
    char barcode[5];
    printf("Введите штрих-код (4 цифры): ");
    scanf("%s", barcode);

    int index = findProductIndexByBarcode(barcode);
    if (index != -1) {
        printf("Название: %s\nЦена: %d руб.\nСкидка: %d%%\n", products[index].name, products[index].price, products[index].discount);
    } else {
        printf("Товар не найден\n");
    }
}

void addToReceipt() {
    char barcode[5];
    printf("Введите штрих-код (4 цифры): ");
    scanf("%s", barcode);

    int index = findProductIndexByBarcode(barcode);
    if (index != -1) {
        int found = 0;
        for (int i = 0; i < scannedCount; i++) {
            if (strcmp(scannedProducts[i].product.barcode, products[index].barcode) == 0) {
                scannedProducts[i].quantity++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(scannedProducts[scannedCount].product.barcode, products[index].barcode);
            strcpy(scannedProducts[scannedCount].product.name, products[index].name);
            scannedProducts[scannedCount].product.price = products[index].price;
            scannedProducts[scannedCount].product.discount = products[index].discount;
            scannedProducts[scannedCount].quantity = 1;
            scannedCount++;
        }
        printf("Товар добавлен в чек\n");
    } else {
        printf("Товар не найден\n");
    }
}

void generateReceipt() {
    int totalCost = 0;
    int totalDiscount = 0;
    printf("\nЧек:\n");

    for (int i = 0; i < scannedCount; i++) {
        int discountedPrice = scannedProducts[i].product.price * (100 - scannedProducts[i].product.discount) / 100;
        int totalForProduct = discountedPrice * scannedProducts[i].quantity;
        totalCost += totalForProduct;
        totalDiscount += (scannedProducts[i].product.price - discountedPrice) * scannedProducts[i].quantity;
        printf("%s - %d руб. (%d%%) - %d шт. - %d руб.\n", scannedProducts[i].product.name, scannedProducts[i].product.price, scannedProducts[i].product.discount, scannedProducts[i].quantity, totalForProduct);
    }

    int finalAmount = totalCost;
    printf("\nОбщая стоимость: %d руб.\nСкидка: %d руб.\nИтоговая сумма: %d руб.\n", totalCost, totalDiscount, finalAmount);
    scannedCount = 0; 
}

void calculateTotalAmount() {
    int totalCost = 0;
    int totalDiscount = 0;

    for (int i = 0; i < scannedCount; i++) {
        int discountedPrice = scannedProducts[i].product.price * (100 - scannedProducts[i].product.discount) / 100;
        int totalForProduct = discountedPrice * scannedProducts[i].quantity;
        totalCost += totalForProduct;
        totalDiscount += (scannedProducts[i].product.price - discountedPrice) * scannedProducts[i].quantity;
    }

    int finalAmount = totalCost;
    printf("\nИтоговая сумма к оплате: %d руб.\n", finalAmount);
}

int main() {
    setlocale(LC_ALL,"Rus");
    

    addProduct("1234", "Хлеб", 30, 5);
    addProduct("5678", "Молоко", 50, 10);
    addProduct("9012", "Яблоки", 100, 15);
    addProduct("3456", "Сок", 70, 0);

    int choice;
    do {
        printf("\nВыберите операцию:\n");
        printf("1. Сканировать товар\n");
        printf("2. Вывести описание отсканированного товара\n");
        printf("3. Добавить данные о товаре в чек\n");
        printf("4. Сформировать чек\n");
        printf("5. Рассчитать итоговую сумму к оплате\n");
        printf("6. Выйти\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanProduct();
                break;
            case 2:
                scanProduct();
                break;
            case 3:
                addToReceipt();
                break;
            case 4:
                generateReceipt();
                break;
            case 5:
                calculateTotalAmount();
                break;
            case 6:
                printf("Выход из программы\n");
                break;
            default:
                printf("Неверный выбор\n");
        }
    } while (choice != 6);

    return 0;
}