#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double sin_taylor(double x, int n);
double cos_taylor(double x, int n);
double exp_taylor(double x, int n);
double arsh_taylor(double x, int n);


typedef double (*taylor_series_func)(double, int);


double calculate_taylor_series(taylor_series_func func, double x, int n_max, double precision) {
    double approximation = 0.0;
    double term = 1.0; 
    int n = 1;

    while (n <= n_max && fabs(term) > precision) {
        if (n > 1) {
            term = func(x, n);
        }
        approximation += term;
        n++;
    }

    return approximation;
}

double sin_taylor(double x, int n) {
    double sign = (n % 2 == 0) ? -1 : 1;
    return sign * pow(x, 2 * n - 1) / tgamma(2 * n);
}

double cos_taylor(double x, int n) {
    double sign = (n % 2 == 0) ? 1 : -1;
    return sign * pow(x, 2 * n - 2) / tgamma(2 * n - 1);
}

double exp_taylor(double x, int n) {
    return pow(x, n - 1) / tgamma(n);
}

double arsh_taylor(double x, int n) {
    return pow(x, 2 * n - 1) / ((2 * n - 1) * tgamma(n));
}

int main() {
    int mode;
    printf("Select mode:\n1. Single calculation\n2. Series experiment\n");
    scanf("%d", &mode);

    int function_choice;
    printf("Select function:\n1. sin(x)\n2. cos(x)\n3. exp(x)\n4. arsh(x)\n");
    scanf("%d", &function_choice);

    taylor_series_func selected_function;
    switch (function_choice) {
        case 1:
            selected_function = sin_taylor;
            break;
        case 2:
            selected_function = cos_taylor;
            break;
        case 3:
            selected_function = exp_taylor;
            break;
        case 4:
            selected_function = arsh_taylor;
            break;
        default:
            printf("Invalid function choice.\n");
            return 1;
    }

    double x;
    printf("Enter point x: ");
    scanf("%lf", &x);

    if (mode == 1) {
        int n_max;
        double precision;
        printf("Enter number of elements (N): ");
        scanf("%d", &n_max);
        printf("Enter precision: ");
        scanf("%lf", &precision);

        double approximation = calculate_taylor_series(selected_function, x, n_max, precision);
        double actual_value;
        switch (function_choice) {
            case 1:
                actual_value = sin(x);
                break;
            case 2:
                actual_value = cos(x);
                break;
            case 3:
                actual_value = exp(x);
                break;
            case 4:
                actual_value = log(x + sqrt(x * x + 1));
                break;
        }
        printf("Actual value: %.10f\n", actual_value);
        printf("Approximation: %.10f\n", approximation);
        printf("Difference: %.10f\n", fabs(actual_value - approximation));
        printf("Number of terms used: %d\n", n_max);
    } else if (mode == 2) {
        int n_max;
        printf("Enter number of experiments (NMax): ");
        scanf("%d", &n_max);

        double actual_value;
        switch (function_choice) {
            case 1:
                actual_value = sin(x);
                break;
            case 2:
                actual_value = cos(x);
                break;
            case 3:
                actual_value = exp(x);
                break;
            case 4:
                actual_value = log(x + sqrt(x * x + 1));
                break;
        }
        printf("Actual value: %.10f\n", actual_value);
        printf("Terms\tApproximation\tDifference\n");

        for (int n = 1; n <= n_max; n++) {
            double approximation = calculate_taylor_series(selected_function, x, n, 0.0);
            printf("%d\t%.10f\t%.10f\n", n, approximation, fabs(actual_value - approximation));
        }
    } else {
        printf("Invalid mode selection.\n");
    }

    return 0;
}
