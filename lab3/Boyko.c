#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("enter a length of a number\n");
    // custom length
    int length;
    int flag = 0;
    do {
        if (flag) {
            printf("this lenght is out of range\ntry again\n");
        }
        scanf_s("%d", &length);
        
        flag = 1;
    } while (length < 2 || length > 5);
    // number generator
    int number[5] = {0};
    srand(time(NULL));
    int c, j;
    number[0] = (rand() % 9) + 1;
    for (int i = 1; i < 5; i++) {
        j = i;
        c = rand() % 10;
        while (j > 0) {
            if (c == number[i - j]) {
                c = rand() % 10;
                j = i;
            }
            else {
                j--;
            }  
        }
        number[i] = c;
    }
    char d;
    for (int i = 0; i < length; i++) {
        d = 48 + number[i];
        printf("%c", d);
    }
    printf("\n");
    // random number definer
    int rannumholder = 0;
    int dec_value = 1;
    for (int i = 0; i < length; i++) {
        rannumholder += number[length - 1 - i] * dec_value;
        dec_value *= 10;
    }
    while (getchar() != '\n');
    int yournumholder = 0;
    printf("now guess the number\n");
    while (rannumholder != yournumholder) {
        // custom number
        char yours[5] = { 0 };
        for (int i = 0; i < length; i++) {
            char c = getchar();
            if (c < '0' || c > '9') {
                while (getchar() != '\n');
                printf("there can be only numbers\n");
                i = 0;
            }
            else {
                yours[i] = c;
            }
        }
        while (getchar() != '\n');
        // bulls & cows
        int bulls = 0, cows = 0;
        for (int i = 0; i < length; i++) {
            if (number[i] == yours[i] - 48) {
                bulls += 1;
            }
            else {
                for (int j = 0; j < length; j++) {
                    if (yours[i] - 48 == number[j]) {
                        cows += 1;
                    }
                }
            }
        }
        // custom number definer
        yournumholder = 0;
        dec_value = 1;
        for (int i = 0; i < length; i++) {
            yournumholder += (yours[length - 1 - i] - 48) * dec_value;
            dec_value *= 10;
        }
        if (bulls == length) {
            break;
        }
        else {
            printf("\nbulls - %d\n", bulls);
            printf("cows - %d\n\n", cows);
        }
    }
    printf("you guessed it");
}
