#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define KEY_SIZE 5 // barcode - 4 symbols + \0
#define QUANTITY_OF_COMMANDS 5
#define NAME_MAX_SIZE 30
#define QUANTITY_OF_PRODUCTS 10
#define RECEIPT_MAX_SIZE 1000

typedef unsigned int uint;

struct product {
  char key[KEY_SIZE];
  char name[NAME_MAX_SIZE + 1]; // for \0
  float price;
  unsigned int discount;
};

const struct product products[QUANTITY_OF_PRODUCTS] = {
    {"1234\0", "Milk\0", 100.00F, 20},   {"5678\0", "Bread\0", 40.00F, 15},
    {"9012\0", "Apples\0", 80.00F, 25},  {"3456\0", "Cheese\0", 200.00F, 10},
    {"7890\0", "Meat\0", 300.00F, 35},   {"2345\0", "Nuts\0", 150.00F, 12},
    {"4567\0", "Juice\0", 70.00F, 18},   {"8901\0", "Chocolate\0", 120.00F, 22},
    {"6789\0", "Coffee\0", 250.00F, 28}, {"0123\0", "Tea\0", 90.00F, 17}};

int get_product_id() {

  int scanned_product_id = -1;
  char input_barcode[KEY_SIZE] = {'\0'};

  printf("Enter barcode: ");
  scanf("%s", input_barcode);
  /*printf("%s\t%lu\n", input_barcode, strlen(input_barcode));*/

  for (int i = 0; i < QUANTITY_OF_PRODUCTS; i++) {
    if (strcmp(input_barcode, products[i].key) == 0) {
      scanned_product_id = i;
      break;
    }
  }

  return scanned_product_id;
}

void print_description_of_product(const uint product_id) {
  printf("Barcode: %s\nName: %s\nPrice: %f\nDiscount: %d\n",
         products[product_id].key, products[product_id].name,
         products[product_id].price, products[product_id].discount);
}

float get_total_sum(const uint quantity_of_each_product[]) {
  float total_sum = 0;

  for (int i = 0; i < QUANTITY_OF_PRODUCTS; i++) {
    total_sum += quantity_of_each_product[i] * products[i].price *
                 (100 - products[i].discount) / 100.0F;
  }

  return total_sum;
}

bool is_empty(const uint quantity_of_each_product[]) {
  bool all_zeroes = true;

  for (int i = 0; i < QUANTITY_OF_PRODUCTS; i++) {
    if (quantity_of_each_product[i] != 0) {
      all_zeroes = false;
    }
  }

  return all_zeroes;
}

int main() {
  int scanned_product_id = -1;
  uint quantity_of_each_product[QUANTITY_OF_PRODUCTS] = {0};

  while (true) {
    printf("Main menu:\n(number of command) - description\n");
    printf("(0) - Exit\n(1) - Scan product\n(2) - Get description of scanned "
           "product\n(3) - Add to the receipt\n(4) - Generate the receipt\n(5) "
           "- Get total sum\n");

    uint command = 0;
    do {
      scanf("%d", &command);

      if (command > QUANTITY_OF_COMMANDS) {
        printf("Please, enter correct command\n");
      }
    } while (command > QUANTITY_OF_COMMANDS);

    if (command == 0) {
      break;
    }
    if (command == 1) {
      do {
        scanned_product_id = get_product_id();

        if (scanned_product_id == -1) {
          printf("Couldn't find your barcode, repeat, please\n");
        }
      } while (scanned_product_id == -1);
      printf("\n");
    } else if (command == 2) {
      if (scanned_product_id == -1) {
        printf("Before you receive the description, scan a product, please\n");
        continue;
      }

      print_description_of_product(scanned_product_id);

      printf("\n");
    } else if (command == 3) {
      if (scanned_product_id == -1) {
        printf("Before I can add a product, scan one, please\n");
        continue;
      }

      quantity_of_each_product[scanned_product_id]++;

      printf("Product was added to the receipt\n");

      printf("\n");
    } else if (command == 4) {
      if (is_empty(quantity_of_each_product)) {
        printf("Before you receive the receipt, scan at least one product, "
               "please\n");
        continue;
      }

      for (int i = 0; i < QUANTITY_OF_PRODUCTS; i++) {
        if (quantity_of_each_product[i] == 0) {
          continue;
        }

        float product_sum = products[i].price * quantity_of_each_product[i] *
                            (100 - products[i].discount) / 100.0F;
        printf("%s\tx%d\t%d%%\t%f rubles\n", products[i].name,
               quantity_of_each_product[i], products[i].discount, product_sum);
      }
      printf("\n");
    } else if (command == 5) {
      printf("TOTAL SUM: %f rubles\n", get_total_sum(quantity_of_each_product));
      printf("\n");

      for(int i = 0; i < QUANTITY_OF_PRODUCTS; i++){
        quantity_of_each_product[i] = 0;
      }
      scanned_product_id = -1;
    }
  }

  return 0;
}
