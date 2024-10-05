#include <stdio.h>
#include <math.h>
#include <locale.h>
void main_();
void main()
{
    float DSP = 0.00075, DVP = 0.00085, WOOD = 0.00065;
    setlocale(LC_ALL, "rus");
    float wnH, wnW, wnL;
    float minH = 183, maxH = 223, minW = 80 + 3, maxW = 120 + 3, minL = 0.5 + 50 + 1, maxL = 90 + 1.5;
    float s1, s2, s3, s4, s5, s6;
    printf("Введите желаемые высоту, ширину и глубину:\n");
    scanf_s("%f %f %f", &wnH, &wnW, &wnL);
    if ((wnH <= maxH) && (wnH >= minH) && (wnW <= maxW) && (wnW >= minW) && (wnL <= maxL) && (wnL >= minL)) {
        s1 = (wnH - 3) * DVP * (wnW - 3) * 0.5;
        s2 = (wnH - 3) * (wnL - 1.5) * DSP * 1.5 * 2;
        s3 = 2 * 1.5 * wnW * wnL * DSP;
        s4 = WOOD * wnH * wnW;
        s5 = floor((wnH - 3) / 40);
        s6 = DSP * (wnW - 3) * 1 * (wnL - 1.5) * s5;
        printf("Суммарный вес шкафа равен %f килограмм", s1 + s2 + s3 + s4 + s6);

    }
    else printf("Я НИ БУДУ ЭТА ДЕЛАЦ!!!!!!!!");

    main_();
}
void main_()
{
    int choosing = 0;
    setlocale(LC_ALL, "rus");
    int x1, y1, x2, y2;
    printf("Введите координаты первой клетки:\n");
    scanf_s("%d %d", &x1, &y1);
    printf("Введите координаты второй клетки:\n");
    scanf_s("%d %d", &x2, &y2);
    printf("Выберете фигуру: 1-Король, 2-Ферзь, 3-Ладья, 4-Слон, 5-Конь\n");
    scanf_s("%d", &choosing);
    if ((x1 < 9) && (x1 > 0) && (x2 < 9) && (x2 > 0) && (y1 < 9) && (y1 > 0) && (y2 < 9) && (y2 > 0)) {
        if (choosing == 1) {
            if ((x2 <= x1 + 1) && (x2 >= x1 - 1) && (y2 <= y1 + 1) && (y2 >= y1 - 1)) {
                printf("Может");
            }
            else printf("Не может");
        }
        else if (choosing == 2) {
            if ((x2 <= x1 + 1) && (x2 >= x1 - 1) && (y2 <= y1 + 1) && (y2 >= y1 - 1) || (abs(x1 - x2) == abs(y1 - y2))) {
                printf("Может");
            }
            else printf("Не может");
        }
        else if (choosing == 3) {
            if (x2 == x1 || y1 == y2) {
                printf("Может");
            }
            else printf("Не может");
        }
        else if (choosing == 4) {
            if (abs(x1 - x2) == abs(y1 - y2)) {
                printf("Может");
            }
            else printf("Не может");
        }
        else if (choosing == 5) {
            if ((abs(x1 - x2) == 3 && abs(y1 - y2) == 1) || (abs(x1 - x2) == 1 && abs(y1 - y2) == 3)) {
                printf("Может");
            }
            else printf("Не может");
        }
        else if (choosing == 0) {
            printf("Shutdown programm 1000-7");
        }
        else printf("Такой опции нет, так что\nПрощай, товарищ!");
    }
    else printf("\n\n\nАБУБАБА ТЫ ГДЕ В ШАХМАТЫ ИГРАТЬ УЧИЛСЯ ЭТО НЕ НАРДЫ ЧУРКА БЛИН\n\n\n");
}

