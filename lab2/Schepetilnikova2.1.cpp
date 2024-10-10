// Первый режим

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

void main() {
	setlocale(LC_ALL, "rus");
	int cm, pl, n{};
	srand(time(NULL));
	cm = 1 + rand() % 1001;
	printf("Программа загадала число от 1 до 1000. Попробуйте угадать число!\n");
	scanf_s("%d", &pl);
	if (pl == cm) {
		printf("Ура! Вы угадали с первого раза!\n");
		printf("Число ваших попыток: %d\n", n = 1);
	}
	else {
		while (pl != cm) {
			printf("Попробуйте ещё!\n");
			scanf_s("%d", &pl);
			n = n + 1;
			if (pl < cm)
				printf("Загаданное число больше, чем ваше\n");
			else if (pl > cm)
				printf("Загаданное число меньше, чем ваше\n");
			else
				printf("Вы угадали!\n");
		}
	}
	printf("Число ваших попыток: %d\n", n + 1);
}