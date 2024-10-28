#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	char names_of_items[100][30] = { {0} };
	int barcodes[100] = { 0 }, flag = -1, i = 0, sz_n_o_i = sizeof(names_of_items[0]), duplicate[100] = { 0 };
	float prices_of_items[100] = { 0 }, invoice = 0;
	while (i < 100) {
		printf("\nEnter the barcode and price of item: ");
		if (scanf_s("%d %f", &barcodes[i], &prices_of_items[i]) != 1) {
			while (getchar() != '\n');
		}
		if (barcodes[i] < 0 || barcodes[i] > 9999)
			barcodes[i] = 0;
		else {
			for (int k = 0; k < i; k++) {
				if (barcodes[k] == barcodes[i]) {
					prices_of_items[i] = prices_of_items[k];
					break;
				}
			}
			while (prices_of_items[i] <= 0) {
				printf("\nSystem error price can't be lower than 0 enter the price again: ");
				if (scanf_s("%d", &prices_of_items[i]) != 1)
					while (getchar() != '\n');
			}
			printf("\nEnter name of item: ");
			fgets(names_of_items[i], sz_n_o_i, stdin);
			i++;
		}
		printf("\nIf you want to get a total enter 0 | else enter any number: ");
		if (scanf_s("%d", &flag) != 1) {
			while (getchar() != '\n');
		}
		if (!flag) {
			break;
		}
	}
	printf("\n");
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		if (barcodes[i] > 0 && !duplicate[i]) {
			duplicate[i]++;
			int cnt_of_item = 1, discount = 1 + rand() % 50;
			for (int j = i + 1; j < 100; j++) {
				if (barcodes[j] == barcodes[i]) {
					cnt_of_item++;
					duplicate[j]++;
				}
			}
			float tmp = cnt_of_item * prices_of_items[i] * (100.0 - discount) / 100.0;
			invoice += tmp;
			printf("%s occurs %d times discount for this item is %d percent | total cost of this item is %.2f\n", names_of_items[i], cnt_of_item, discount, tmp);
		}	
	}
	printf("\nThe total value is %.2f\n", invoice);
	return 0;
}