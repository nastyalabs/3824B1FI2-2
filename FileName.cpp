#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "RUS");
	int size = 0, number = 0, bulls = 0, cows = 0;
	int Bn[5] = {}, a[10] = {}, n[5];

	srand(time(NULL));
	printf("Укажите длину числа:\n");
	scanf_s("%d", &size);
	Bn[0] = 1 + rand() % 9;
	a[Bn[0]] = 1;
	for (int i = 1; i < size; ++i) {
		do {
			Bn[i] = rand() % 10;

		} while (a[Bn[i]] == 1);
		a[Bn[i]] = 1;
	}
	do {
		printf("Введите число: ");
		scanf_s("%d", &number);
		for (int i = size - 1; i >= 0; --i) {
			n[i] = number % 10;
			number /= 10;
		}
		for (int i = 0; i < size; ++i) {
			if (n[i] == Bn[i]) {
				bulls++;
			}
			else {
				for (int j = 0; j < size; ++j) {
					if (n[i] == Bn[j]) {
						cows++;
					}
				}
			}
		}
		if (bulls == size) {
			printf("Поздравляю! Вы угадали число.");
			break;
		}
		printf("Количество коров = %d, количество быков = %d.\n", cows, bulls);
		cows = 0;
		bulls = 0;
	} while (true);

}