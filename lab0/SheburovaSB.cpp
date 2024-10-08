#include <stdio.h>
#include <math.h>
#include <locale.h>
int main() {
	setlocale(LC_ALL, "Russian");
	int x1, x2, y1, y2, r1, r2;
	double res;
	scanf_s("%d %d %d %d %d %d", &x1, &x2, &y1, &y2, &r1, &r2);
	res = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (r1 + r2 == res) {
		printf("КАСАЕТСЯ\n");
	}
	else if (r1 + r2 < res) {
		printf("НЕПЕРЕСЕКАЮТСЯ\n");
	}
	else {
		printf("ПЕРЕСЕКАЮТСЯ\n");
	}
	return 0;

}