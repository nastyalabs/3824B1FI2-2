#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <sec_api/string_s.h>

typedef struct {
    char name[20];
    int size;
} Document;

void bubbleSort(Document documents[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (documents[j].size > documents[j + 1].size) {
                Document temp = documents[j];
                documents[j] = documents[j + 1];
                documents[j + 1] = temp;
            }
        }
    }
}

void selectionSort(Document documents[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (documents[j].size < documents[minIndex].size) {
                minIndex = j;
            }
        }
        Document temp = documents[minIndex];
        documents[minIndex] = documents[i];
        documents[i] = temp;
    }
}

void printDocuments(Document documents[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\n", documents[i].name, documents[i].size);
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int choice;
    printf("Выберите путь к документу (введите цифру):\n");
    printf("1) Пользователи..Рабочий стол..Мой документ\n");
    printf("2) Пользователи..Рабочий стол..Моя библиотека\n");
    printf("3) Пользователи..Рабочий стол..Моё\n");
    printf("4) Пользователи..Рабочий стол..Моё учебное\n");
    printf("5) Пользователи..Рабочий стол..Дом\n");
    printf("Ваш выбор: ");
    scanf_s("%d", &choice);
    Document documents[5];
    int documentCount = 0;

    switch (choice) {
    case 1:
        strcpy_s(documents[0].name, "doc_1"); documents[0].size = 5;
        strcpy_s(documents[1].name, "doc_2"); documents[1].size = 3;
        strcpy_s(documents[2].name, "doc_3"); documents[2].size = 8;
        strcpy_s(documents[3].name, "doc_4"); documents[3].size = 8;
        strcpy_s(documents[4].name, "lib_4"); documents[4].size = 10;
        documentCount = 5;
        break;
    case 2:
        strcpy_s(documents[0].name, "lib_1"); documents[0].size = 4;
        strcpy_s(documents[1].name, "lib_2"); documents[1].size = 10;
        strcpy_s(documents[2].name, "lib_3"); documents[2].size = 6;
        strcpy_s(documents[3].name, "lib_4"); documents[3].size = 12;
        strcpy_s(documents[4].name, "lib_5"); documents[4].size = 4;
        documentCount = 5;
        break;
    case 3:
        strcpy_s(documents[0].name, "me_1"); documents[0].size = 1;
        strcpy_s(documents[1].name, "me_2"); documents[1].size = 3;
        strcpy_s(documents[2].name, "me_3"); documents[2].size = 10;
        strcpy_s(documents[3].name, "me_4"); documents[3].size = 35;
        strcpy_s(documents[4].name, "me_5"); documents[4].size = 2;
        documentCount = 5;
        break;
    case 4:
        strcpy_s(documents[0].name, "study_1"); documents[0].size = 10;
        strcpy_s(documents[1].name, "study_2"); documents[1].size = 1;
        strcpy_s(documents[2].name, "study_3"); documents[2].size = 18;
        strcpy_s(documents[3].name, "study_4"); documents[3].size = 7;
        strcpy_s(documents[4].name, "study_5"); documents[4].size = 13;
        documentCount = 5;
        break;
    case 5:
        strcpy_s(documents[0].name, "home_1"); documents[0].size = 5;
        strcpy_s(documents[1].name, "home_2"); documents[1].size = 8;
        strcpy_s(documents[2].name, "home_3"); documents[2].size = 2;
        strcpy_s(documents[3].name, "home_4"); documents[3].size = 14;
        strcpy_s(documents[4].name, "home_5"); documents[4].size = 1;
        documentCount = 5;
        break;
    default:
        printf("Неверный выбор!\n");
        return 0;
    }

    printf("Вывод документов:\n");
    printDocuments(documents, documentCount);

    int sortMethod;
    printf("Выберите метод сортировки:\n");
    printf("1) Сортировка пузырьком\n");
    printf("2) Сортировка выбором\n");
    printf("Ваш выбор: ");
    scanf_s("%d", &sortMethod);
    clock_t start, end;
    double usedTime;
    if (sortMethod == 1) {
        start = clock();
        bubbleSort(documents, documentCount);
        printf("Документы, отсортированные пузырьком:\n");
        end = clock();
        usedTime = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Пузырьковая сортировка выполнена за %.10lf секунд.\n", usedTime);
    }
    else if (sortMethod == 2) {
        start = clock();
        selectionSort(documents, documentCount);
        printf("Документы, отсортированные выбором:\n");
        end = clock();
        usedTime = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Сортировка выбором выполнена за %.10lf секунд.\n", usedTime);
    }
    else {
        printf("Неверный выбор метода сортировки!\n");
        return 0;
    }
    printDocuments(documents, documentCount);
    return 0;
}