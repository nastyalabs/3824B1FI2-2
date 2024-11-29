#include <stdio.h>
#include <math.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "rus");
	float dsp = 0.00075, dvp = 0.00075, tree = 0.00065;
	float h, w, d;
	float c1, c2, c3, c4, c5;
	printf("ВВедите высоту, ширину и глубину шкафа:\n");
	scanf_s("%f %f %f", &h, &w, &d);
	if ((h >= 180) && (h <= 220) && (w >= 80) && (w <= 120) && (d >= 50) && (d <= 90)) {
		c1 = h * w * dvp * 0.5;
		c2 = 2 * dsp * h * d * 1.5;
		c3 = 2 * dsp * w * d * 1.5;
		c4 = 2 * tree * h * w * 1;
		float a = floor(h / 40);
		c5 = a * dsp * w * d * 1;
		float sm = c1 + c2 + c3 + c4 + c5;
		printf("Масса шкафа: %f", sm);
	}
}