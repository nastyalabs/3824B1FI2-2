#include <stdio.h>
#include <math.h>

int minimum(int a1, int a2) {
	return a1 < a2 ? a1 : a2;
}
int maximum(int a1, int a2) {
	return a1 > a2 ? a1 : a2;
}

void main() {
	int x1, x2, y1, y2, r1, r2, h;
	printf("x1, y1, r1: ");
	scanf_s("%d %d %d", &x1, &y1, &r1);
	printf("x2, y2, r2: ");
	scanf_s("%d %d %d", &x2, &y2, &r2);
	h = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (h == r1 + r2) {
		printf("circles intersect in one point from the outside");
	}
	else if (h == 0 && fabs(r1 - r2) > 0) {
		printf("one circle is in another");
	}
	else if (h == 0 && r1 == r2) {
		printf("circles overlap");
	}
	else if (maximum(r1, r2) == minimum(r1, r2) + h) {
		printf("circles intersect in one point from the inside");
	}
	else if (r1 + r2 > h && maximum(r1, r2) < h) {
		printf("circles intersect in two points from the outside");
	}
	else if (maximum(r1, r2) < h + minimum(r1, r2)) {
		printf("circles intersect in two points from the inside");
	}
	
	else {
		printf("Seems like it's out of 2-dimentional space");
	}

}