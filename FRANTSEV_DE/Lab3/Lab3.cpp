#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>



int main()
{
    int mode;
    setlocale(LC_ALL, "rus");
    printf("Выберите задачу:\n1 - НОД\n2 - Сумма чисел\n3 - Найти по сумме чисел\n4 - Wordly, Lab3\n5 - Быки и коровы\n");
    scanf_s("%d", &mode);
    if (mode == 1) {
        system("cls");
        int a, b, ost = 28, c, d;
        printf("Введите два числа, у которых надо найти НОД: \n");
        scanf_s("%d %d", &a, &b);
        if (a > b) { c = a; d = b; }
        else { c = b; d = a; }
        while (ost != 0) {
            ost = c % d;
            c = d;
            d = ost;
        }
        printf("НОД равен %d", c);
    }
    else if (mode == 2) {
        system("cls");
        char c[2];
        int nado, summ = 0;
        printf("Введите число у которого надо найти сумму чисел: \n");
        scanf_s("%d", &nado);
        while (nado != 0) {
            summ += nado % 10;
            nado = nado / 10;
        }
        printf("\n\n%d\n\n", summ);
    }
    else if (mode == 3) {
        while (getchar() != '\n');
        system("cls");
        int nado, summ = 0, counter = 0, countercopy;
        printf("Введите искомую сумму чисел: \n");
        scanf_s("%d", &nado);
        while (counter < 999) {
            counter+= 1;
            summ = 0;
            countercopy = counter;
            while (countercopy != 0) {
                summ += countercopy % 10;
                countercopy = countercopy / 10;
            }
            if (summ == nado){
                printf("%d\n", counter);
            }
        }
    }
    else if (mode == 4) {
        while (getchar() != '\n');
        system("cls");
        printf("Введите длину слова: \n");
        int length, counter = -1, counter1 = 0, counterx2 = -1, bebra = 0, sovpadenia = 0, popitki;
        scanf_s("%d", &length);
        printf("Введите количество попыток: \n");
        scanf_s("%d", &popitki);
        while (getchar() != '\n');
        char c[6], d[6];
        printf("Введите само слово:\n");
        fgets(c, length+1, stdin);
        while (getchar() != '\n');
        system("cls");
        while (sovpadenia != length) {
            sovpadenia = 0;
            if (popitki != 0) {
                printf("Попытайтесь угадать слово с количеством букв: %d\n", length);
                printf("Осталось попыток: %d\n", popitki);
                fgets(d, length + 1, stdin);
                while (getchar() != '\n');
                counter = -1;
                counter1 = 0;
                while (counter < length - 1) {
                    counter++;
                    counterx2 = -1;
                    counter1++;
                    bebra = 0;
                    if ((c[counter] == d[counter]) && (c[counter] != '\n')) { printf("%d - совпадение\n", counter1); sovpadenia += 1; bebra = 1; }
                    else {
                        while (counterx2 < length - 1) {
                            counterx2++;
                            if (d[counter] == c[counterx2]) { printf("%d - присутствие\n", counter1); bebra = 1; break; }
                        }
                    }
                    if (bebra == 0) printf("%d - отсутствие\n", counter1);
                }
                popitki -= 1;


                
            }
            else {printf("\nПопытки кончились, вы проиграли!\n"); break;}
            } 
        if (sovpadenia == length) printf("\nВы угадали!\n");
        }
    else if (mode == 5) {
        system("cls");
        char c[6] = {"\0"}, d[6];
        int length, popitki, nageneril, raz, bebra, sovpadenia = 0, counter = -1, counter1 = 0, counterx2 = -1, bebra2 = 0;
        srand(time(NULL));
        printf("Введите длину числа: \n");
        scanf_s("%d", &length);
        printf("Введите количество попыток: \n");
        scanf_s("%d", &popitki);
        c[0] = 48+(1 + (rand() % 9));
        for (int i = 1; i < length; i++) {
            bebra = 0;
            while (bebra == 0) {
                raz = 0;
                nageneril = 48+ (rand() % 10);
                for (int l = 0; l < i; l++) {
                    if (c[l] != nageneril) { raz++; }
                }
                if (raz == i) {
                    c[i] = nageneril;
                    bebra = 1;
                }
            }
        }
        while (getchar() != '\n');
        system("cls");
        while (sovpadenia != length) {
            sovpadenia = 0;
            if (popitki != 0) {
                printf("\nПопытайтесь угадать число с количеством цифр: %d\n", length);
                printf("Осталось попыток: %d\n", popitki);
                fgets(d, length + 1, stdin);
                while (getchar() != '\n');
                counter = -1;
                counter1 = 0;
                while (counter < length - 1) {
                    counter++;
                    counterx2 = -1;
                    counter1++;
                    bebra2 = 0;
                    if ((c[counter] == d[counter]) && (c[counter] != '\n')) { printf("%d - совпадение\n", counter1); sovpadenia += 1; bebra2 = 1; }
                    else {
                        while (counterx2 < length - 1) {
                            counterx2++;
                            if (d[counter] == c[counterx2]) { printf("%d - присутствие\n", counter1); bebra2 = 1; break; }
                        }
                    }
                    if (bebra2 == 0) printf("%d - отсутствие\n", counter1);
                }
                popitki -= 1;



            }
            else { printf("\nПопытки кончились, вы проиграли!\n"); break; }
        }
        if (sovpadenia == length) printf("\nВы угадали!\n");
    }
    else printf("PIPISKA\n");
}

