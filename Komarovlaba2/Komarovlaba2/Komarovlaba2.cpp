#include <stdio.h>
#include <stdlib.h>
//lab2.1
/*int main() {
	int magic_number1 = 1 + rand() % 1000;
	int our_number1 = -1, cnt_of_try = 0;
	while (our_number1 != magic_number1) {
		printf("Enter your number: ");
		scanf_s("%d", &our_number1);
		cnt_of_try++;
		if (our_number1 > magic_number1)
			printf("Your number is bigger than magic number\n");
		else if (our_number1 == magic_number1) {
			printf("Congratulation! You guessed it!\n");
			printf("You spend %d attempts", cnt_of_try);
		}
		else
			printf("Your number is lower than magic number\n");
	}
	return 0;
}
*/
//lab2.2 Не понятно условие насчёт считается ли словом последовательность символов заканчивающаяся на ! или ? например: привет! - это же слово? а если а! одна буква и знак это слово или нет?
// Поэтому сделал без учёта слов оканчивающихся на ! или ? т.к. в условии задачи написано что слово это последовательность букв латинского алфавита.
int main() {
	int cnt_of_words = 0, cnt_of_numbers = 0;
	char last_letter = getchar();
	char c;
	while ((c = getchar()) != '\n' && last_letter != '\n') {
		if (c == ' ' && last_letter != ' ') {
			if (last_letter >= 'A' && last_letter <= 'z')
				cnt_of_words++;
			else if (last_letter >= '0' && last_letter <= '9')
				cnt_of_numbers++;
		}
		last_letter = c;
	}
	if (last_letter != ' ') {
		if (last_letter >= 'A' && last_letter <= 'z') {
			cnt_of_words++;
		}
		else if (last_letter >= '0' && last_letter <= '9') {
			cnt_of_numbers++;
		}
	}
	printf("Your string has %d words and %d numbers\n", cnt_of_words, cnt_of_numbers);
	return 0;
}