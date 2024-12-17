#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>

long double sinxx(double x) {
	return sin(x);
}
long double cosxx(double x) {
	return cos(x);
}
long double expxx(double x) {
	return exp(x);
}
long double tgxx(double x) {
	return atan(x);
}
double factorial(int a) {
	if (a == 1 || a == 0) { return 1; }
	return a * factorial(a - 1);
}
long double sinx(double x, int ste, double(*op)(double, int), double(*fact)(int)) {
	if (ste == 0) { return 0; }
	else {
		long double result = (op(-1, ste - 1) * op(x, (2 * ste) - 1) / fact(2 * ste - 1)) + sinx(x, ste - 1, op, fact);
		return result;
	}
	
}
long double cosx(double x, int ste, double(*op)(double, int), double(*fact)(int)) {
	if (ste == 0) { return 1; }
	else {
		long double result = (op(-1, ste) * op(x, (2 * ste)) / fact(2 * ste)) + cosx(x, ste - 1, op, fact);
		return result;
	}
}
long double expx(double x, int ste, double(*op)(double, int), double(*fact)(int)) {
	if (ste == 0) { return 1; }
	else {
		long double result = (op(x, ste) / fact(ste)) + expx(x, ste - 1, op, fact);
	}
}
long double tgx(double x, int ste, double(*op)(double, int), double(*fact)(int)) {
	if (ste == 0) { return 0; }
	else {
		long double result = (op(-1, ste-1) * op(x, (2 * ste)-1) / (2 * ste-1)) + tgx(x, ste - 1, op, fact);
		return result;
	}
}
double step(double x, int n) {
	long double result = 1;
	for (int j = 0; j < n; j++) {
		result *= x;
	}
	return result;
}



int main()
{
	setlocale(LC_ALL, "rus");
	int x0 = 0, mode = 0;
	double result = 0, x = 0.0;
	printf("Choose a mode:\n1 - Однократный расчет функции в заданной точке.\n2 - Серийный эксперимент.\n");
	scanf_s("%d", &mode);
	long double (*types[4])(double, int, double(double, int), double(int)) = { sinx, cosx, expx, tgx };
	long double (*typesx[4])(double) = { sinxx, cosxx, expxx, tgxx };
	if (mode == 0) {
		printf("Moya tvoya truba shatal eu ti");
	}

	else if (mode == 1) {
		int num_func;
		printf("Выберите функцию:\n1 - sin\n2 - cos\n3 - exp\n4 - arctan\n");
		scanf_s("%d", &num_func);
		if (num_func != 1 && num_func != 2 && num_func != 3 && num_func != 4) {
			printf("ОШИБКА БЕБРЫ");
			return 0;
		}
		num_func -= 1;
		printf("Введите x, в котором нужно произвести вычисление:\n");
		scanf_s("%lf", &x);
		int num_of_symb;
		printf("Введите количество знаков после запятой (6 или больше):\n");
		scanf_s("%d", &num_of_symb);
		int num_of_elem;
		printf("Выберите число элементов ряда (от 1 до 1000):\n");
		scanf_s("%d", &num_of_elem);
		double cpy = x/90;
		if (num_func == 0 || num_func == 1) {
			x = (int)x % 360;
			x = x/ 57.2958;
		}

		if (num_func == 0) {
			if (cpy == 0 || cpy == 2) {
				printf("\n\n0\n\n");
				return 0;
			}
			if (cpy == 1) {
				printf("\n\n1\n\n");
				return 0;
			}
			if (cpy == 3) {
				printf("\n\n-1\n\n");
				return 0;
			}

		}
		if (num_func == 1) {
			if (cpy == 1 || cpy == 3) {
				printf("\n\n0\n\n");
				return 0;
			}
			if (cpy == 0) {
				printf("\n\n1\n\n");
				return 0;
			}
			if (cpy == 2) {
				printf("\n\n-1\n\n");
				return 0;
			}

		}
		if (num_func == 3 && (x > 1 ||x < -1)) {
			printf("\n\nНевозможно вычислить по формуле Тейлора для такого X\n\n");
			return 0;
		}
		/*char c[512] = "Dildo - %.";
		char c3[3] = "Lf";
	
		strcat_s(c ,512, num_of_symb);
		for (int i = 0; i < 512; i++) {
			if (c[i] == '\n') {
				c[i] = '\0';
				break;
			}
		}
		strcat_s(c,512, c3);
		printf("%s\n", c);*/
		char aboba1[64];
		char aboba2[64];
		char aboba3[64];
		long double result = types[num_func](x, num_of_elem, step, factorial);
		long double bebra = typesx[num_func](x);
		snprintf(aboba1, sizeof aboba1, "%.30Lf", result);
		snprintf(aboba2, sizeof aboba1, "%.30Lf", bebra);
		snprintf(aboba3, sizeof aboba1, "%.30Lf", bebra - result);
		int gay = 0;
		for (int i = 0; i < 64; i++) {
			if (aboba2[i] == ',') {
				gay = i;
				break;
			}
		}
		printf("\n\nЭталонное значение в точке X - ");
		for (int i = 0; i < num_of_symb+1+gay; i++) {
			printf("%c", aboba2[i]);
		}
		printf("\n");
		printf("Вычисленный результат в точке X - ");
		for (int i = 0; i < num_of_symb+1+gay; i++) {
			printf("%c", aboba1[i]);
		}
		printf("\n");
		printf("Разница между значениями - ");
		for (int i = 0; i < num_of_symb; i++) {
			printf("%c", aboba3[i]);
		}
		printf("\nКоличество слагаемых - %d\n\n", num_of_elem);



	}
	else if (mode == 2) {
		int num_func;
		printf("Выберите функцию:\n1 - sin\n2 - cos\n3 - exp\n4 - arctan\n");
		scanf_s("%d", &num_func);
		if (num_func != 1 && num_func != 2 && num_func != 3 && num_func != 4) {
			printf("ОШИБКА БЕБРЫ");
			return 0;
		}
		num_func -= 1;
		printf("Введите x, в котором нужно произвести вычисление:\n");
		scanf_s("%lf", &x);
		int num_of_elem;
		printf("Выберите количество экспериментов (от 1 до 1000):\nВнимание! Номер эксперимента соответствует количеству слагаемых в формуле Тейлора!\n");
		scanf_s("%d", &num_of_elem);
		double cpy = x / 90;
		if (num_func == 0 || num_func == 1) {
			x = (int)x % 360;
			x = x / 57.2958;
		}

		if (num_func == 0) {
			if (cpy == 0 || cpy == 2) {
				printf("0");
				return 0;
			}
			if (cpy == 1) {
				printf("1");
				return 0;
			}
			if (cpy == 3) {
				printf("-1");
				return 0;
			}

		}
		if (num_func == 1) {
			if (cpy == 1 || cpy == 3) {
				printf("0");
				return 0;
			}
			if (cpy == 0) {
				printf("1");
				return 0;
			}
			if (cpy == 2) {
				printf("-1");
				return 0;
			}

		}
		if (num_func == 3 && (x > 1 || x < -1)) {
			printf("\n\nНевозможно вычислить по формуле Тейлора для такого X\n\n");
			return 0;
		}
		printf("Номер                Полученное                           Идеальное                      Разность\n");
		long double bebra = typesx[num_func](x);
		for (int i = 1; i < num_of_elem+1; i++) {
			long double result = types[num_func](x, i, step, factorial);
			printf("%d           %.20Lf            %.20Lf             %.20Lf\n", i, result, bebra, bebra - result);
		}

		
	}
	else printf("PIPISKA BOLSHOI TOLSTIY HUI\n");
}