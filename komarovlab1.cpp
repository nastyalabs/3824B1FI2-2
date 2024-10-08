#include <stdio.h>
#include <math.h>
/*void main() {
	unsigned int a, b, c;
	printf("Enter the lengths of triangle\n");
	scanf_s("%d %d %d", &a, &b, &c);
	if ((a + b > c) && (a + c > b) && (b + c > a)) {
		if ((a == b) && (b == c))
			printf("Ravnost");
		else if ((a == b) || (b == c) || (a == c))
			printf("Ravnobedr");
		else if ((a * a + b * b == c * c) || (b * b + c * c == a * a) || (a * a + c * c == b * b))
			printf("Pryamoug");
		else
			printf("Proizvol");
	}
	else
		printf("Triangle doesn't exist");
}
*/
/*void main() {
	int a = 0, b = 0, c = 0;
	float disc = 0;
	printf("Enter coef\n");
	scanf_s("%d %d %d", &a, &b, &c);
	disc = b * b - 4 * a * c;
	if (disc > 0) {
		printf("%.3lf", (-b + sqrt(disc)) / 2 * a);
		printf("%.3lf", (-b - sqrt(disc)) / 2 * a);
	}
	else if (disc == 0)
		printf("%d", -b / 2 * a);
	else
		printf("Korney net");
}
*/
/*void main() {
	float h, w, t1 = 0.5, stenka = 0, p_dvp = 0.82, p_dsp = 0.8, mass;
	printf("Enter h, w\n");
	scanf_s("%f %f", &h, &w);
	stenka = p_dvp * h * w * t1;
	float d, t2 = 1.5, bokovina, krishki, doors, polki;
	printf("Enter d\n");
	scanf_s("%f", &d);
	bokovina = p_dsp * 2 * h * d * t2;
	krishki = p_dsp * 2 * w * d * t2;
	doors = p_dsp * 2 * h * w;
	polki = h / 40 * krishki / 2;
	mass = stenka + bokovina + krishki + doors + polki;
	printf("Massa = %f", mass / 1000);
}
*/
bool king(int x1, int x2, int y1, int y2) {
	if ((abs(x1 - x2) <= 1) && (abs(y1 - y2) <= 1) && !(x1 == x2 && y1 == y2))
		return 1;
	return 0;
}
bool ferz(int x1, int x2, int y1, int y2) {
	if ((y1 == y2 || x1 == x2 || abs(x1 - x2) == abs(y1 - y2)) && !(x1 == x2 && y1 == y2))
		return 1;
	return 0;
}
bool ladiya(int x1, int x2, int y1, int y2) {
	if ((y1 == y2 || x1 == x2) && !(x1 == x2 && y1 == y2))
		return 1;
	return 0;
}
bool slon(int x1, int x2, int y1, int y2) {
	if ((abs(x1 - x2) == abs(y1 - y2)) && !(x1 == x2 && y1 == y2))
		return 1;
	return 0;
}
bool kon(int x1, int x2, int y1, int y2) {
	if ((abs(x1 - x2) == 2) && (abs(y1 - y2) == 1) || (abs(x1 - x2) == 1) && (abs(y1 - y2) == 2))
		return 1;
	return 0;
}


void main() {
	signed int x1, x2, y1, y2, figure;
	printf("Enter x1, x2, y1, y2, figure: 0 - King, 1 - Ferz, 2 - Ladiya, 3 - Slon, 4 - Kon\n");
	scanf_s("%d %d %d %d %d", &x1, &x2, &y1, &y2, &figure);
	if ((figure > 4) || (x1 > 8 || x1 == 0) || (x2 > 8 || x2 == 0) || (y1 > 8 || y1 == 0) || (y2 > 8 || y2 == 0))
		printf("Figure or squares doesn't exists\n");
	else {
		bool m_king = king(x1, x2, y1, y2), m_ferz = ferz(x1, x2, y1, y2), m_ladiya = ladiya(x1, x2, y1, y2), m_slon = slon(x1, x2, y1, y2), m_kon = kon(x1, x2, y1, y2);
		if (figure == 0) {
			if (m_king == 1)
				printf("Mozhet\n");
			else {
				printf("%s\n", m_ferz == 1 ? "Mozhet ferzem" : "Ne mozhet ferzem");
				printf("%s\n", m_ladiya == 1 ? "Mozhet ladiei" : "Ne mozhet ladiei");
				printf("%s\n", m_slon == 1 ? "Mozhet slonom" : "Ne mozhet slonom");
				printf("%s\n", m_kon == 1 ? "Mozhet konem" : "Ne mozhet konem");
			}
		}
		else if (figure == 1) {
			if (m_ferz == 1)
				printf("Mozhet\n");
			else {
				printf("%s\n", m_king == 1 ? "Mozhet korolem" : "Ne mozhet korolem");
				printf("%s\n", m_ladiya == 1 ? "Mozhet ladiei" : "Ne mozhet ladiei");
				printf("%s\n", m_slon == 1 ? "Mozhet slonom" : "Ne mozhet slonom");
				printf("%s\n", m_kon == 1 ? "Mozhet konem" : "Ne mozhet konem");
			}
		}
		else if (figure == 2) {
			if (m_ladiya == 1)
				printf("Mozhet\n");
			else {
				printf("%s\n", m_king == 1 ? "Mozhet korolem" : "Ne mozhet korolem");
				printf("%s\n", m_ferz == 1 ? "Mozhet ferzem" : "Ne mozhet ferzem");
				printf("%s\n", m_slon == 1 ? "Mozhet slonom" : "Ne mozhet slonom");
				printf("%s\n", m_kon == 1 ? "Mozhet konem" : "Ne mozhet konem");
			}
		}
		else if (figure == 3) {
			if (m_slon == 1)
				printf("Mozhet\n");
			else {
				printf("%s\n", m_king == 1 ? "Mozhet korolem" : "Ne mozhet korolem");
				printf("%s\n", m_ferz == 1 ? "Mozhet ferzem" : "Ne mozhet ferzem");
				printf("%s\n", m_ladiya == 1 ? "Mozhet ladiei" : "Ne mozhet ladiei");
				printf("%s\n", m_kon == 1 ? "Mozhet konem" : "Ne mozhet konem");
			}
		}
		else {
			if (m_kon == 1)
				printf("Mozhet\n");
			else {
				printf("%s\n", m_king == 1 ? "Mozhet korolem" : "Ne mozhet korolem");
				printf("%s\n", m_ferz == 1 ? "Mozhet ferzem" : "Ne mozhet ferzem");
				printf("%s\n", m_ladiya == 1 ? "Mozhet ladiei" : "Ne mozhet ladiei");
				printf("%s\n", m_slon == 1 ? "Mozhet konem" : "Ne mozhet konem");
			}
		}
	}
}
