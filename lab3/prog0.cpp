#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <cstdlib>
#include <math.h>
#include <stdbool.h>


bool a(int number) {
    char a[10] = { 0 };

    while (number!=0) {
        int b = number % 10;
        number = number / 10;
        a[b] += 1;
    }
    
    for (int i = 0; i < 10; i++) {
        if (a[i] > 1) {
            return false;
        }
    }
    return true;
}

bool a1(int sou, int b) {
    while (sou != 0) {
        int cus = sou % 10;
        if (b == cus) {
            return true;
        }
        sou = sou / 10;
    }
    return false;
}

int a2(int sou, int pos) {
    return (sou % (int)pow(10, pos)) / (int)pow(10, pos - 1);
}


int main() { 
    int n;
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    printf("Введите число от 2 до 5:\n");
    scanf_s("%d", &n);
    int dlin = (int)pow(10, n-1);
    int sou;
    do {
        sou = dlin + rand() % ((int)pow(10, n) - dlin);
    } while (!a(sou));
    printf("%d\n", sou);
    int input;
    do {
        printf("Ведите число:\n");
        scanf_s("%d", &input);
        int number = input;
        int cows = 0, bulls = 0;
        for (int i = 1; i <= n; i++) {
            int digit = number % 10;
            number /= 10;
            if (a1(sou, digit)) {
                cows++;
            }
            if (a2(sou, i) == digit) {
                bulls++;
            }
        }
        printf("cows: %d, bulls: %d\n", cows, bulls);
    } while (input != sou);
    printf("Победа");
    return 0;
}
