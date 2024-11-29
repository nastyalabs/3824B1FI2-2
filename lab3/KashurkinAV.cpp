#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <cstdlib>
#include <math.h>
#include <stdbool.h>


bool is_unique_digits(int number) {
    char digits_count[10] = { 0 };

    while (number!=0) {
        int digit = number % 10;
        number = number / 10;
        digits_count[digit] += 1;
    }
    
    for (int i = 0; i < 10; i++) {
        if (digits_count[i] > 1) {
            return false;
        }
    }
    return true;
}

bool is_digit_in(int source, int digit) {
    while (source != 0) {
        int current_digit = source % 10;
        if (digit == current_digit) {
            return true;
        }
        source = source / 10;
    }
    return false;
}

int get_digit(int source, int pos) {
    return (source % (int)pow(10, pos)) / (int)pow(10, pos - 1);
}


void main() { 
    int n;
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    printf("Введите число от 2 до 5:\n");
    scanf_s("%d", &n);
    int lower = (int)pow(10, n-1);
    int source;
    do {
        source = lower + rand() % ((int)pow(10, n) - lower);
    } while (!is_unique_digits(source));
    printf("%d\n", source);
    int input_number;
    do {
        printf("Ведите число:\n");
        scanf_s("%d", &input_number);
        int number = input_number;
        int cows = 0, bulls = 0;
        for (int i = 1; i <= n; i++) {
            int digit = number % 10;
            number /= 10;
            if (is_digit_in(source, digit)) {
                cows++;
            }
            if (get_digit(source, i) == digit) {
                bulls++;
            }
        }
        printf("cows: %d, bulls: %d\n", cows, bulls);
    } while (input_number != source);
    printf("you are winner!!!");
}