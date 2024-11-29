#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int h, w, g;
	double DBP = 0.85, DCP = 0.7, D = 0.72;
	double s1, b1, b2, kv1, kn1, d1, d2, p, M;
	double t1 = 0.5;
	double t2 = 1.5;
	double t3 = 1.5;
	double t4 = 1.0;
	scanf_s("%d %d %d",&h, &w, &g);
	if (((180 < h) && (h < 220)) && ((80 < w) && (w < 120)) && ((50 < g) && (g < 90))) {
		s1 = ((h * w) * t1) * DBP;
		b1 = ((h * g) * t2) * DCP;
		b2 = ((h * g) * t2) * DCP;
		kv1 = ((w * g) * t3) * DCP;
		kn1 = ((w * g) * t3) * DCP;
		d1 = ((w * h) * t4) * D;
		d2 = ((w * h) * t4) * D;
		if (h <= 199) {
			p = (((w * g) * t3) * DCP) * 4;}
		else {
			p = (((w * g) * t3) * DCP) * 5;}
		M = (s1 + b1 + b2 + kv1 + kn1 + d1 + d2 + p)/1000;
		printf("%f кг\n", M);
	}
	else {
		printf("Введите корректные данные\n");}
	return 0;
}