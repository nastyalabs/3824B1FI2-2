#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "rus");
    int mode;
    printf("Выберите режим игры:\n1 - Вы отгадываете\n2 - Вы загадываете\n");
    scanf_s("%d", &mode);
    if (mode == 1) {
        srand(time(NULL));
        int THINK = 1 + (rand() % 1000);
        int YOUTHINK = 1002;
        printf("Число от 1 до 1000 загадано. Игра начинается...\n\n");
        while (YOUTHINK != THINK){
            printf("Введите число ==> ");
            scanf_s("%d", &YOUTHINK);
            if (YOUTHINK != THINK) {
                if (YOUTHINK > THINK) { printf("Ваше число больше!\n\n"); }
                else printf("Ваше число меньше!\n\n");
            }
        }
        printf("Вы угадали!\n");
    }
    else if (mode == 2) {
        system("cls");
        int think = 500, down = 0, up = 1000;
        int youthink, counter = 1;
        char oper[2];
        printf("Загадывайте число: ");
        scanf_s("%d", &youthink);
        //fflush(stdin);
        while (getchar() != '\n');
        if (youthink >= 0 && youthink <= 1000) {
            while (think != youthink) {
                counter++;
                printf("Число %d больше, меньше или равно?\n", think);
                fgets(oper, 2, stdin);
                while (getchar() != '\n');
                if (oper[0] == '<') {
                    down = think;
                    think = (think + up) / 2;

                }
                else if (oper[0] == '>') {
                    up = think;
                    think = (think + down) / 2;
                }
                else if (oper[0] == '=') {
                    printf("Ты поддался... Спасибо?\n");
                }
                else {printf("\n\n\nТакого действия нет, барашек\n\n\n"); return 0;
            }
            }
            if (think == youthink) {
                printf("Число %d больше, меньше или равно?\n", think);

                fgets(oper, 2, stdin);
                while (getchar() != '\n');
                if (oper[0] == '=') { printf("Победа\n"); }
                else printf("Грязный лжец.");
             
            }
            printf("\n\nПопыток на угадывание вашего числа: %d\n\n", counter);
        }
        else printf("Ваше число слишком большое!");
    }
    else printf("Поиграй сам с собой, дуралей\n");
}

