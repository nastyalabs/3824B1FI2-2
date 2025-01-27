#include <stdio.h>

void main() {
	int h, w, d, t2 = 1, den1 = 1, i;
	int v1, v2, v3, m;
	float t1 = 0.5, t3 = 1.5, den2 = 0.8, den3 = 0.65;
	printf("enter a height, a width, a depth (in cm): ");
	scanf_s("%d %d %d", &h, &w, &d);
	if (h > 220 || h < 180 || w > 120 || w < 80 || d > 90 || d < 50) {
		printf("out of range");
	}
	else {
		i = (h - 1) / 40;
		v1 = (h * w * t1);
		v2 = 2 * (h * d * t3) + (2 + i) * (d * w * t3);
		v3 = (h * w * t2);
		m = (v1 * den1 + v2 * den2 + v3 * den3) / 1000;
		printf("%dkg", m);
	}
}