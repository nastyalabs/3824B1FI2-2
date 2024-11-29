#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "rus");
	int mx = 1000, mn = 1, n, sr;
	int k = 0;
	char c = ' ';
	scanf_s("%d", &n);
	while (c != '=')
	{
		sr = (mx + mn) / 2;
		printf("%d?\n", sr);
		while (getchar() != '\n');
		c = getchar();
		k = k + 1;
		if (c == '>') {
			mn = sr + 1;
		}
		else if (c == '<') {
			mx = sr - 1;
		}
		else if (c == '=') {
			break;
		}
	}
	printf("good %d", k);
}
/*#include <stdio.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "rus");
	int n;
	int a;
	scanf_s("%d", &n);
	do
	{
		scanf_s("%d", &a);
		if (a > n) {
			printf("Загаданное число меньше");
		}
		if (a < n) {
			printf("Загаданное число больше");
		}

	} while (n != a);
	printf("Вы угадали!!!");
}*/