#include <stdio.h>
#include <locale.h>
int main(){
    setlocale (LC_ALL,"Russian");
    float h, w, a, m1, m2, m3,V, M, pd = 0.6, pdsp = 0.7, pdvp = 1.0, t1 = 0.5, t2 = 1.5, t3 = 1.0;
//h,w,a,V - высота, ширина , глубина, объем
//m3,m1,m2,M - масса оставшихся часей, м стенки cзади, м дверей,м всего
//pd,pdvp,t1,t2,t3 - постоянные плотности дерева, ДВП,толщины
    int d,b;
    printf("Введите высоту,ширину задней стены, глубину боковой\n");
    scanf_s("%f %f %f",&h, &w, &a);
    if ((h > 220) || (h < 180) || (w > 120) || (w < 80) || (a > 90) || (a < 50)) {
        printf("Неверные данные");
    }else{
        d = h/40;
        m1 = h*w*t1*pdvp;
        m2 = h*w*t3*pd;
        m3 = 2*h*a*t2*pdsp + 2*w*a*t2*pdsp+d*w*a*t2*pdsp;
        M = (m1+m2+m3)/1000;
        b = M;
        printf("Шкаф весит: %d кг (%1.f)%f",b,M,M);
    }
    return 0;
}
