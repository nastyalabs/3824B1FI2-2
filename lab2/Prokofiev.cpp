#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void main() {
	int mode, hidden_number = 0, answer, attempt = 0;
	scanf_s("%d", &mode);
	if (mode == 1) {
		srand(time(0));
		hidden_number = rand() % 1001;
		do {
			printf("enter\n");
			scanf_s("%d", &answer);
			attempt++;
			if (answer > hidden_number) {
				printf("<\n");
			}
			else if (answer < hidden_number) {
				printf(">\n");
			}
			else {
				printf("victory , attempt = %d\n", attempt);
			}
		} while (answer != hidden_number);
	}
	else {
		int low = 1, high = 1000;
		char sign;
		printf("enter hidden number\n");
		scanf_s("%d", &hidden_number);
		do {
			attempt++;
			answer = (low + high) / 2;
			printf("my answer is %d. Is this > < =\n", answer);
			scanf_s(" %c", &sign);
			if (sign == '>') {
				low = answer + 1;
			}
			else if (sign == '<') {
				high = answer - 1;
			}
			else if (sign == '=') {
				printf("ez, attemp = %d\n", attempt);
			}
		} while (answer != hidden_number);
	}
}