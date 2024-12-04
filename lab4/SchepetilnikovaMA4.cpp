#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define size 9



char products[size][100] = {"Яблоко","Груша","Персик","Виноград","Слива","Мандарин","Банан","Апельсин","Манго"};
int code[size][5] = {{3,9,4,6,1},{3,7,5,3,2},{3,2,8,0,3},{3,7,5,1,4},{1,4,3,6,5},{3,7,2,5,6},{4,0,6,1,7},{ 3,2,5,1,7 },{ 3,9,6,7,7 }};
int cost[size] = {34, 45, 55, 110, 30, 43, 31, 65, 120};
int sale[size] = {5,20,20,10,15,0,0,25,10};

int shopping[size][5];

int c[size] = { 0 };

int find_products(int p) {
	int a;
	a = p % 10;
	return a;
}

double sale2(int* shopping) {
	float cost_with_sale;
	int i = 0;
	for (i; i < size;i++) {
		int flag = 1;
		for (int j = 0; j < 5;j++) {
			if (code[i][j] != shopping[i])
				flag = 0;
		}
		if (flag)
			break;
	}
	cost_with_sale = (float)(cost[i]) * ((float)(100 - sale[i]));
	return cost_with_sale;
}

void main() {
	setlocale(LC_ALL, "rus");
	for (int i = 0; i < size;i++) {
		for (int j = 0; j < 5;j++) {
			shopping[i][j] = code[i][j];
		}
	}

	int cnt_of_shopping = -1;
	printf("Добро пожаловать в магазин! \n");
	printf("Весь ассортримент: \n");
	printf("Продукт                     Код         Цена    \n");
	for (int i = 0; i < size; i++) {
		printf("%-25s - ", products[i]);
		for (int j = 0; j < 5;j++) {
			printf("%d", code[i][j]);
		}
		printf(" - %8hi", cost[i]);
		printf("\n");
	}
	printf("Выберите продукт\n");
	printf("Если хотите закончить, нажмите 1\n");
	int shopping[5] = { 0 };
	int p = 0;
	while (1) {
		scanf_s("%hi", &p);
		if (p == 1) break;
		while (p != 0) {
			for (int i = 4; i >= 0; i--) {
				shopping[i] = find_products(p);
				p /= 10;
			}
		}

		int j = 0;
		for (j; j < size; j++) {
			int count = 0;
			for (int i = 0; i < 5; i++) {
				if (shopping[i] == code[j][i]) {
					count++;
				}
				else
					count = 0;
				if (count == 5) {
					for (j; j < size; j++) {
						printf("%s", products[j]);
						printf(" ");
						c[j]++;
						for (int i = 0; i < 5; i++) {
							printf("%i", code[j][i]);
						}
						
						printf("  Скидка = %d %% \n", sale[j]);
						break;
					}
				}
			}
		}

	}
	printf("\n\n\nПокупки Кол-во     Цена             Скидка        Итог \n");
	float summary_sale = 0, total = 0;
	for (int i = 0; i < size; i++) {
		if (c[i] != 0) {
			for (int k = 0; k < 25; k++) printf("%c", products[i][k]);
			printf("   %d", c[i]);
			printf("           %d", cost[i]);
			printf(" %18.2f", cost[i] * (float)(sale[i]) / 100);
			printf(" %15.2f\n", (float)cost[i] * (float)c[i] * (float)(100 - sale[i]) / 100);
			total = total + c[i] * cost[i];
			summary_sale += c[i] * cost[i] * (float)(sale[i]) / 100;
		}
	}
	printf("\n Итог: %.2f\n Сукидка: %.2f руб\n\nК оплате: %.2f\n\n", total, summary_sale, total - summary_sale);
}
