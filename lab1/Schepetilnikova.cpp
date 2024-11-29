#include<stdio.h>
#include<locale.h>

void main() {
	setlocale(LC_ALL, "rus");
	double DVP = 0.7, h, w, tl1, DCP = 0.6, d, tl2, tl3, tl4, plotnoct, massa,zadnaya_stenka,bok,kr,doors,polky;
	tl1 = 0.5; //Толщина накладной задней стенки в см
	tl2 = 1.5;//Толщина боковин в см
	tl3 = 1.5;//Толщина крышек в см
	tl4 = 1;//Толщина двери
	plotnoct = 1, 5;// Плотность дерева

	printf("Введите размеры шкафа (высоту, ширину, глубину). Введите высоту(см):\n");
	scanf_s("%lf",&h);
	printf("Введите ширину, глубину(см):\n");
	scanf_s("%lf", &w);
	printf("Введите глубину(см):\n");
	scanf_s("%lf", &d);

	if (h >= 180 && h <= 220 && w >= 80 && w <= 120 && d >= 50 && d <= 90) {
		zadnaya_stenka = h * d * tl1;
		bok = 2 * h * d * tl2;
		kr = 2 * w * d * tl3; //Крышки (верхняя и нижняя)
		doors = 2 * h * w * tl4;
		polky = (h/40);

		massa = zadnaya_stenka * DVP + bok * DCP + kr * DCP + doors * plotnoct + polky * DCP;
		printf("Масаа шкафа %lf (гр)", massa);
	}
	else {
		printf("Введены неправильные данные, попробуйте ещё раз.\n");
	}
}