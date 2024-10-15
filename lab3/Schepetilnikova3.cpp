#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

void main() {
	setlocale(LC_ALL, "rus");
	int n, bulls = 0, cows = 0, x, pl;
	printf("Укажите длину загадываемого числа (от 2 до 5)\n");
	scanf_s("%d", &n);
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	int numbers[5], our_numbers[5];
	srand(time(NULL));
	x = 0 + rand() % 9;

	numbers[0] = a[x];
	a[x] = 999;
	for (int i = 0; i < n; i++) {
		numbers[i] = 0+ rand() % 10;
	}

	do {
		bulls = 0; cows = 0;
		printf("Угадай число длиной: %d\n", n);
		scanf_s("%d", &pl);
		if (pl == 0) {
			printf("Конец игры! \n");
			break;
		}
		for (int i = n - 1; i >= 0; i--) {
			x = pl % 10;
			our_numbers[i] = x;
			pl = pl / 10;
		}
		for (int i = 0; i < n; i++) {
			if (numbers[i] == our_numbers[i]) {
				bulls++;
			}
			for (int j = 0; j < n; j++) {
				if (numbers[i] == our_numbers[j])
					cows++;
			}
		}
		cows = cows - bulls;
		printf("Количество коров: %d\n", cows);
		printf("Количество быков: %d\n", bulls);
		if (bulls == n)
			printf("Ура! Вы угадали!\n");
	} while (bulls != n);
}