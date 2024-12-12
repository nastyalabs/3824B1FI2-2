#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

long long int factorial(int n) {
	long long int i, b = 1;
	if ((n == 0) || (n == 1)) {
		return 1;
	}
	else if (n > 1) {
		for (i = 1; i <= n; i++) {
			b *= i;
		}
		return b;
	}
	else {
		return 1;
	}
}

long double my_pow(long double n, int m) {
	long double a = 1;
	if (m >= 0) {
		for (int i = 0; i < m; i++) {
			a *= n;
		}
		return a;
	}
	else {
		for (int i = 0; i < (m * (-1)); i++) {
			a *= n;
		}
		return 1 / a;
	}
	
}

double my_sin(double n, int k) {
	double sum = 0, a = 0, rem = 0;
	if (n >= 0) {
		for (int i = 1; i < (n / 2 / PI); i++) {
			a = 2*i * PI;
		}
		rem = n - a;
	}
	else {
		for (int i = -1; i > (n / 2 / PI); i--) {
			a = 2*i;
		}
		rem = (n/PI - a)*PI;
	}
	for (int i = 0; i <= k; i++) {
		sum += my_pow(-1, i) * my_pow(rem, 2 * i + 1) / factorial(2 * i + 1);
	}
	if (sum > 1) sum = 1;
	if (sum < -1) sum = -1;
	return sum;
}

double my_cos(double n, int k) {
	double sum = 0, a = 0, rem = 0;
	if (n >= 0) {
		for (int i = 1; i < (n / 2 / PI); i++) {
			a = 2 * i * PI;
		}
		rem = n - a;
	}
	else {
		for (int i = -1; i > (n / 2 / PI); i--) {
			a = 2 * i;
		}
		rem = (n / PI - a) * PI;
	}
	for (int i = 0; i <= k; i++) {
		sum += my_pow(-1, i) * my_pow(rem, 2 * i) / factorial(2 * i);
	}
	if (sum > 1) sum = 1;
	if (sum < -1) sum = -1;
	return sum;
}

double my_exp(int n, int k) {
	double sum = 0;
	for (int i = 0; i <= k; i++) {
		sum += my_pow(n, i)/factorial(i);
	}
	return sum;
}

double arcsin(double n, int k) {
	double sum = 0;
	if (n <= 1 && n >= -1) {
		for (int i = 0; i <= k; i++) {
			sum += factorial(2 * i) * my_pow(n, 2 * i + 1) / (my_pow(2, 2 * i) * factorial(i) * factorial(i) * (2 * i + 1));
		}
		return sum;
	}
	else return 0;
}

double arccos(double n, int k) {
	return (PI / 2) - arcsin(n, k);
}

double arctan(double n, int k) {
	double sum = 0, a;
	if (n <= 1 && n >= -1) {
		for (int i = 0; i <= k; i++) {
			sum += my_pow(-1, i) * my_pow(n, 1 + 2 * i) / (1 + 2 * i);
		}
		return sum;
	}
	else if (n > 1 || n < -1) {
		for (int i = 0; i <= k; i++) {
			sum += my_pow(-1, i) * my_pow(n, -1 - 2 * i) / (1 + 2 * i);
		}
		a = (PI * sqrt(my_pow(n, 2)) / 2 / n) - sum;
		return a;
	}
}

double arccot(double n, int k) {
	double sum = 0, a;
	if (n <= 1 && n >= -1) {
		for (int i = 0; i <= k; i++) {
			sum += my_pow(-1, i + 1) * my_pow(n, 1 + 2 * i) / (1 + 2 * i);
		}
		a = (PI / 2) + sum;
		return a;
	}
	else if (n > 1 || n < -1) {
		for (int i = 0; i <= k; i++) {
			sum += my_pow(-1, i) * my_pow(n, -1 - 2 * i) / (1 + 2 * i);
		}
		return sum;
	}
}

int rounder(double r) {
	double a = 0.000001;
	int b;
	while ((fabs(a - r) / a) > 8 && a != 1) {
		a *= 10;
	}
	b = 1 / a;
	return b;
}

void md1sc(char c ,double x, int n, int r) {
	double dif = 0, ref = 0, appr = 0;
	switch (c - 48) {
	case 1: {
		ref = sin(x);
		appr = my_sin(x, n);
		dif = fabs(ref - appr);
		printf("sine\n");
		break;
	}
	case 2: {
		ref = cos(x);
		appr = my_cos(x, n);
		dif = fabs(ref - appr);
		printf("cosine\n");
		break;
	}
	case 3: {
		ref = exp(x);
		appr = my_exp(x, n);
		dif = fabs(ref - appr);
		printf("exponential function\n");
		break;
	}
	case 4: {
		ref = asin(x);
		appr = arcsin(x, n);
		dif = fabs(ref - appr);
		printf("arc sine\n");
		break;
	}
	case 5: {
		ref = acos(x);
		appr = arccos(x, n);
		dif = fabs(ref - appr);
		printf("arc cosine\n");
		break;
	}
	case 6: {
		ref = atan(x);
		appr = arctan(x, n);
		dif = fabs(ref - appr);
		printf("arc tangent\n");
		break;
	}
	case 7: {
		ref = (PI / 2) + atan(x);
		appr = arccot(x, n);
		dif = fabs(ref - appr);
		printf("arc cotangent\n");
		break;
	}
	}
	if (c - 48 >= 0 && c - 48 < 10) {
		printf("reference value: %lf\napproximate value: %lf\nthe difference: %lf\n", round(ref * r) / r, round(appr * r) / r, round(dif * r) / r);
	}
}

void md2sc(char c, double x, int n, int r) {
	double dif;
	switch (c - 48) {
	case 1: {
		printf("sine\n");
		printf("number of terms\t\treference value\t\tapproximate value\t\tthe difference\n");
		for (int i = 1; i <= n; i++) {
			dif = my_sin(x, i) - sin(x);
			printf("%d\t\t\t%lf\t\t%lf\t\t\t%lf\n", i, round(sin(x) * r) / r, round(my_sin(x, i) * r) / r, fabs(round(dif * r) / r));
		}
		break;
	}
	case 2: {
		printf("cosine\n");
		printf("number of terms\t\treference value\t\tapproximate value\t\tthe difference\n");
		for (int i = 1; i <= n; i++) {
			dif = my_cos(x, i) - cos(x);
			printf("%d\t\t\t%lf\t\t%lf\t\t\t%lf\n", i, round(cos(x) * r) / r, round(my_cos(x, i) * r) / r, fabs(round(dif * r) / r));
		}
		break;
	}
	case 3: {
		printf("exponential function\n");
		printf("number of terms\t\treference value\t\tapproximate value\t\tthe difference\n");
		for (int i = 1; i <= n; i++) {
			dif = my_exp(x, i) - exp(x);
			printf("%d\t\t\t%lf\t\t%lf\t\t\t%lf\n", i, round(exp(x) * r) / r, round(my_exp(x, i) * r) / r, fabs(round(dif * r) / r));
		}
		break;
	}
	case 4: {
		printf("arc sine\n");
		printf("number of terms\t\treference value\t\tapproximate value\t\tthe difference\n");
		for (int i = 1; i <= n; i++) {
			dif = arcsin(x, i) - asin(x);
			printf("%d\t\t\t%lf\t\t%lf\t\t\t%lf\n", i, round(asin(x) * r) / r, round(arcsin(x, i) * r) / r, fabs(round(dif * r) / r));
		}
		break;
	}
	case 5: {
		printf("arc cosine\n");
		printf("number of terms\t\treference value\t\tapproximate value\t\tthe difference\n");
		for (int i = 1; i <= n; i++) {
			dif = arccos(x, i) - acos(x);
			printf("%d\t\t\t%lf\t\t%lf\t\t\t%lf\n", i, round(acos(x) * r) / r, round(arccos(x, i) * r) / r, fabs(round(dif * r) / r));
		}
		break;
	}
	case 6: {
		printf("arc tangent\n");
		printf("number of terms\t\treference value\t\tapproximate value\t\tthe difference\n");
		for (int i = 1; i <= n; i++) {
			dif = arctan(x, i) - atan(x);
			printf("%d\t\t\t%lf\t\t%lf\t\t\t%lf\n", i, round(atan(x) * r) / r, round(arctan(x, i) * r) / r, fabs(round(dif * r) / r));
		}
		break;
	}
	case 7: {
		printf("arc cotangent\n");
		printf("number of terms\t\treference value\t\tapproximate value\t\tthe difference\n");
		for (int i = 1; i <= n; i++) {
			dif = arccot(x, i) - (PI / 2) + atan(x);
			printf("%d\t\t\t%lf\t\t%lf\t\t\t%lf\n", i, round(((PI / 2) - atan(x)) * r) / r, round(arccot(x, i) * r) / r, fabs(round(dif * r) / r));
		}
		break;
	}
	}
}

void main() {
	void (*pt) (void);
	int flag = 1;
	printf("1 - mode 1\n2 - mode 2\n0 - exit\n");
	while (flag) {
		int mode;
		printf("choose the mode: ");
		scanf_s("%d", &mode);
		if (mode == 1 || mode == 2) {
			int flag_insider = 1;
			printf("1 - sin\n2 - cos\n3 - exp\n4 - arcsin\n5 - arccos\n6 - arctg\n7 - arcctg\nend - close the program\nhelp - show this text again\n");
			while (flag_insider) {
				double x, r;
				int n, rr;
				double dif;
				char act[4] = { 0 };
				for (int i = 0; i < 4; i++) {
					char c = getchar();
					if (c == '\n') break;
					act[i] = c;
				}
				if ((act[0] == 'h') && (act[1] == 'e') && (act[2] == 'l') && (act[3] == 'p')) {
					printf("1 - sin\n2 - cos\n3 - exp\n4 - arcsin\n5 - arccos\n6 - arctg\n7 - arcctg\nend - close the program\nhelp - show this text again\n");
				}
				if ((act[0] == 'e') && (act[1] == 'n') && (act[2] == 'd')) {
					flag_insider = 0;
					printf("1 - mode 1\n2 - mode 2\n0 - exit\n");
					break;
				}
				if (act[0] > '0' && act[0] < '9') {
					printf("type in your value: ");
					scanf_s("%lf", &x);
					printf("type in the number from 0.000001 and above to round to: ");
					do {
						scanf_s("%lf", &r);
						if (r < 0.000001) printf("the number must be from 0.000001 and above: ");
					} while (r < 0.000001);
					rr = rounder(r);
					if (mode == 1) {
						pt = md1sc;
						printf("type in the number of elements in series: ");
						scanf_s("%d", &n);
						printf("\n");
						pt(act[0], x, n, rr);
					}
					else {
						pt = md2sc;
						do {
							printf("type in the number of experiments: ");
							scanf_s("%d", &n);
							if (n < 1 || n > 25) printf("the number is out of range\n");
						} while (n < 1 || n > 25);
						printf("\n");
						pt(act[0], x, n, rr);
					}
					printf("\n");
					while (getchar() != '\n');
				}
			}
		}
		else if (mode == 0) break;
		else printf("there's no such mode\n");
	}
}