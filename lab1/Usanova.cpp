#include <locale.h>
#include <stdio.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    float y, M, h, w, d, z=0;
    double  m1, m2, m3, pd=0.6, pdvp=1.0, pdsp=0.7, c1=0.5, c2=1.5, c3=1.0;
    printf("Введите высоту от 180 до 220 см, ширину от 80 до 120 см, глубину от 50 до 90 см\n");
    scanf_s("%f %f %f", &h, &w, &d);
    if ((h > 220) || (h < 180) || (w < 80) || (w > 120) || (d < 50) || (d > 90)) {
        printf("Неверные данные\n");
    }
    else {
        m1 = h * w * c1 * pdvp;
        m2 = h * w * c3 * pd;
        m3 = 2 * h * d * c2 * pdsp + 2 * w * d * c2 * pdsp + z * w * d * c2 * pdsp;
        z = h / 40;
        M = (m1 + m2 + m3) / 1000;
        y = M;
        printf("Вес шкафа: %f кг (%.1f) %f", y, M, M);
    }
    return 0;
}
