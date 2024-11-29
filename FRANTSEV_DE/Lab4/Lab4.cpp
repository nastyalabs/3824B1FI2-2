#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>


//1 1 1 1 1 1 1 1 1 1 2 2 2 8 2 2 2 2 2 3
void main() {
	setlocale(LC_ALL, "rus"); 
	int mode = 5;
	while (mode != 0) {
	printf("Выберите задачу:\n1 - Мин Макс\n2 - перевод a в b\n3 - Lab4\n0 - Выход\n");
	
	scanf_s("%d", &mode);
	
		if (mode == 1) {
			int a[20];
			system("cls");
			printf("Введите 20 чисел через пробел: ");
			for (int i = 0; i < 20; i++) {
				scanf_s("%d", &a[i]);
			}

			int min = 10000, max = -10000;
			for (int i = 0; i < 20; i++) {
				if (a[i] > max) { max = a[i]; }

				if (a[i] < min) { min = a[i]; }
			}
			printf("Максимальное: %d\nМинимальное: %d\n", max, min);
			printf("Индексы максимальных: ");
			for (int i = 0; i < 20; i++) {
				if (a[i] == max) { printf("%d ", i); }

			}
			printf("\nИндексы минимальных: ");
			for (int i = 0; i < 20; i++) {
				if (a[i] == min) { printf("%d ", i); }

			}
			printf("\n\n\n");
			mode = 5;
		}
		else if (mode == 2) {
			int a[9], schet = -1;
			char c;
			system("cls");
			printf("Введите число без 0 длиной до 9 символов: ");
			while (getchar() != '\n') {}
			while ((c = getchar()) != '\n') {
				schet += 1;
				a[schet] = c - 48;

			}
			for (int i = 1; i < 10; i++) {
				schet = 0;
				for (int j = 0; j < 9; j++) {
					if (a[j] == i) { schet += 1; }
				}
				printf("%d", schet);
				
			}
			printf("\n\n\n");
		}
		else if (mode == 3) {
			system("cls");
			char items[10][31] = { "Творог 180 г", "Вода 0.5 л", "Молоко 1 л", "Яйца 10 шт", "Торт", "Батон", "Черненький хлеб", "Кока-Кола 1 л", "Кетчуп 200 г", "Майонез 200 г"}, strih[15];
			char codes[10][15] = { "| | ||||\n\0\0\0\0\0", "| || ||||\n\0\0\0\0", "| ||| ||||\n\0\0\0", "|| | ||||\n\0\0\0\0", "|| || ||||\n\0\0\0", "|| ||| ||||\n\0\0", "||| | ||||\n\0\0\0", "||| || ||||\n\0\0", "||| ||| ||||\n\0", "|||| | ||||\n\0\0"};
			int price[10] = { 65, 38, 75, 89, 279, 20, 15, 89, 120, 110 };
			int a, kolvo[10] = { 0 }, summa = 0, itog = 0, sovp = 0;
			while (getchar() != '\n');
			
			while (strih[0] != '0' || strih[1] != '\n') {
				printf("Введите штрихкод: ");
				for (int i = 0; i < 15; i++) { strih[i] = '\0'; }
				fgets(strih, 15, stdin); // || ||| |||| - например
				if (strih[13] == '\n' || strih[13] == '\0') {

					
					sovp = 0;
					for (int i = 0; i < 10; i++) {
						if (strcmp(strih, codes[i]) == 0) { // Написано что это С-шная функция, да и подключается она <string.h>
							kolvo[i] += 1;
							sovp = 1;
						}
					}
					if (sovp == 1) { printf("*пип*\n"); }
					else if (sovp == 0  && strih[0]!= '0' && strih[1] != '\n') { printf("Ошибка чтения штрихкода\n"); }
					else if (sovp == 0 && strih[0] == '0' && strih[1] == '\n') { printf("Печать (генерация) чека...\n"); }
				}
				else { printf("Ошибка чтения штрихкода\n"); while (getchar() != '\n'); }
			}
			printf("\n\n===============================================\n");
			
			for (int i = 0; i < 10; i++) {
				if (kolvo[i] != 0) {
					summa = kolvo[i] * price[i];
					itog += summa;
					printf("%s          %d     %d      %d\n", items[i], price[i], kolvo[i], summa);
				}
			}
			printf("============================Оплачено %d рублей\n\n\n", itog);
			mode = 5;

		}
		else if (mode == 0) { break; }
		else printf("YOU ARE AN ERROR dans la vie\n");
	}
	
}