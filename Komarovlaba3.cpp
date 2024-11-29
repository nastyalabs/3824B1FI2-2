#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	//Bulls & Cows
	int n;
	do {
		printf("Enter number from 2 to 5: \n");
		if (scanf_s("%d", &n) != 1) {
			while (getchar() != '\n');
		}
	} while (!(n >= 2 && n <= 5));
	int x = 10;
	for (int i = 2; i <= n; i++) {
		if (i == n)
			break;
		else
			x *= 10;
	}
	//Компьютер задает рандомное число с неповторяющимися цифрами
	srand(time(NULL));
	int magic_number, flag = 0;
	do {
		magic_number = x + rand() % (x * 9 + 1);
		int c = magic_number, p = 0, digits1[10] = { 0 };
		while (c > 0) {
			digits1[c % 10]++;
			c /= 10;
		}
		for (int i = 0; i < 10; i++) {
			if (digits1[i] > 1) {
				flag = 1;
				p = 1;
				break;
			}
		}
		if (p == 0)
			flag = 0;
	} while (flag);
	//Пользователь вводит n-значное число с неповторящимися цифрами
	int user_number = 0, k = 0;
	do {
		printf("Enter your number: \n");
		if (scanf_s("%d", &user_number) != 1) {
			while (getchar() != '\n');
			flag = 1;
		}
		k = user_number;
		if (x <= user_number && user_number < 10 * x) {
			int l = 0, digits2[10] = { 0 };
			while (k > 0) {
				digits2[k % 10]++;
				k /= 10;
			}
			for (int i = 0; i < 10; i++) {
				if (digits2[i] > 1) {
					flag = 1;
					l = 1;
					break;
				}
			}
			if (l == 0)
				flag = 0;
		}
		else
			flag = 1;
	} while (flag);
	//Сама игра
	int bulls = 0, cows = 0, tmp_us_num = user_number, tmp_mag_num = magic_number;
	int digits_of_magic_number[10] = {0}, digits_of_user_number[10] = {0};
	for (int i = 0; i < n; i++) {
		digits_of_magic_number[tmp_mag_num % 10]++;
		digits_of_user_number[tmp_us_num % 10]++;
		if (tmp_mag_num % 10 == tmp_us_num % 10) {
			bulls++;
			digits_of_magic_number[tmp_mag_num % 10]--;
			digits_of_user_number[tmp_us_num % 10]--;
		}
		tmp_mag_num /= 10;
		tmp_us_num /= 10;
	}
	for (int i = 0; i < 10; i++) {
		if (digits_of_magic_number[i] >= digits_of_user_number[i])
			cows += digits_of_user_number[i];
		else
			cows += digits_of_magic_number[i];
	}
	printf("Magic number is: %d\nYour number is: %d\nResult: %d Bulls, %d Cows", magic_number, user_number, bulls, cows);
	return 0;
}