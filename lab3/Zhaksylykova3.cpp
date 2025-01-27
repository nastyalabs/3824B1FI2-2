#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    srand(time(NULL));
    int n, flag, bulls, cows, count = 0, tmp;
    int hidden[5], used[10] = {0};

    do {
        printf("Enter a number from 2 to 5:\n");
        scanf_s("%d", &n);
        flag = (n < 2 || n > 5);
        if (flag)
            printf("Error, try again\n");
    } while (flag);

    for (int i = 0; i < n; i++) {
        int generated_digit;

        do {
            generated_digit = rand() % 10;
        } while (used[generated_digit] || (i == 0 && generated_digit == 0)); 

        hidden[i] = generated_digit;
        used[generated_digit] = 1;
    }

   /* printf("Hidden number: ");
    for (int i = 0; i < n; i++) {
        printf("%d", hidden[i]);
    }
    printf("\n");*/

    char guess[6];
    do {
        cows = 0;
        bulls = 0;
        printf("Try to guess the number: "); 
        scanf_s("%5s", guess, (unsigned)_countof(guess)); // тяжело
      
        if (strlen(guess) != n) {
            printf("Invalid input. Enter exactly %d digits.\n", n);
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (guess[i] - 48 == hidden[i]) {
                bulls++;
            }
            for (int j = 0; j < n; j++) {
                if ((guess[i] - 48 == hidden[j]) && (i != j)) {
                    cows++;
                }
            }
        }
        printf("Bulls = %d, cows = %d\n", bulls, cows);
    } while (bulls != n); 
    if (bulls = n) {
        printf("Congratulations, you guessed the number\n");
    }
    return 0;
}
