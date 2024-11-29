#include<stdio.h>
#include<math.h>
#include<locale.h>

void main() {
	setlocale(LC_ALL, "rus");
	int x,y = 500, b1 = 0, b2=500, b3=1001, n =1;
	char z;
	printf("Загадайте число от 1 до 1000.\n");
	printf("Если число меньше, введите <\n");
	printf("Если число больше, введите >\n");
	printf("Если число угадано, введите =\n");
	printf("Ваше число %d ?\n", y);
	printf("Введите сравнение: \n");
	printf("%c\n",&z);
	z = getchar();
	while (z != '=') {
		n += 1;
		if (z == '<') {
			x = (b1+b2)/2;
			y = x;
			b3 = b2;
			b2 = y;
		}
		else if (z == '>') {
			x = (b2+b3)/2;
			y = x;
			b1 = b2;
			b2 = y;
		}
		printf("Ваше число %d \n", y);
		printf("Введите сравнение: \n");
		scanf_s("%c", &z);
		z = getchar();
	}
	printf("Компьютер угадал!\n");
	printf("Компьютер угадал за %d попыток\n", n);
}