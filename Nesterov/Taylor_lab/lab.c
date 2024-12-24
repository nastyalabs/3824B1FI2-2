#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "calculations.h"

#define PRECISION_INPUT_MAX_CHARS     100ULL
#define MIN_CALCULATION_PRECISION     0.000001
#define MAX_AMOUNT_OF_TERMS_IN_SERIES 25U
#define SERIES_PRECISION 1e-20

void clear_input_buffer() {
  int buffer_char = 0;
  while ((buffer_char = getchar()) != '\n' && buffer_char != EOF) {}
}

void single_calculation(
    Calc_result_t (*function)(const long double argument, const long double precision,
                              const unsigned short amount_of_terms),
    const double argument, const double standard) {  // NOLINT (*swappablw*)
  printf("Enter precision: ");
  char precision_input[PRECISION_INPUT_MAX_CHARS];
  long double calculation_precision = 0;

  bool is_answer_incorrect = true;
  clear_input_buffer();
  while (is_answer_incorrect) {
    fgets(precision_input, PRECISION_INPUT_MAX_CHARS, stdin);

    calculation_precision = strtold(precision_input, NULL);
    is_answer_incorrect =
        (calculation_precision <= 0 || isnan(calculation_precision));
    if (is_answer_incorrect) { printf("Invalid precision entered\n"); }
  }

  if (calculation_precision > MIN_CALCULATION_PRECISION) {
    calculation_precision = MIN_CALCULATION_PRECISION;
  }

  printf("Amount of terms in row: ");
  unsigned short amount_of_terms_in_row = 1;
  scanf("%hu", &amount_of_terms_in_row);

  Calc_result_t result =
      function(argument, calculation_precision, amount_of_terms_in_row);

  printf("Standard result: %.15lf\n"
         "Calculation result: %.15Lf\n"
         "Difference: %.15Lf\n"
         "Amount of used terms: %u\n",
         standard, result.result, fabsl(standard - result.result),
         result.amount_of_terms_used);
}

void print_row(const unsigned short term_number,
               const long double calculation_result, const long double difference,
               const double standard) {
  printf("| %-25hd | %-29.15Lf | %-29.15Lf | %-29.15lf |\n", term_number,
         calculation_result, fabsl(difference), standard);
}

void series_of_calculations(
    Calc_result_t (*function)(long double argument, long double precision,
                              unsigned short amount_of_terms),
    const double argument, const double standard) {  // NOLINT (*swappablw*)
  printf("Amount of terms: ");
  unsigned short amount_of_terms = 1;
  do {
    scanf("%hd", &amount_of_terms);
    if (amount_of_terms > MAX_AMOUNT_OF_TERMS_IN_SERIES || amount_of_terms == 0) {
      printf("Sorry, value must be in [1, 25]");
    }
  } while (amount_of_terms > MAX_AMOUNT_OF_TERMS_IN_SERIES || amount_of_terms == 0);

  // clang-format off
  printf("+---------------------------+-------------------------------+-------------------------------+-------------------------------+\n");
  printf("|     Amount of terms       |      Calculation result       |           Difference          |           Standard            |\n");
  printf("+---------------------------+-------------------------------+-------------------------------+-------------------------------+\n");
  // clang-format on

  for (int i = 1; i <= amount_of_terms; i++) {
    Calc_result_t result = function(argument, SERIES_PRECISION, i);
    print_row(i, result.result, standard - result.result, standard);
  }
  // clang-format off
  printf("+---------------------------+-------------------------------+-------------------------------+-------------------------------+\n");
  // clang-format on
}

int main() {
  Calc_result_t (*const functions[4])(
      const long double, const long double, const unsigned short) = {my_sin, my_cos, my_exp,
                                                           my_sec};
  double (*const standards[4])(double)                  = {sin, cos, exp, sec};
  while (true) {
    printf("Choose mode:\n"
           "0) Exit\n"
           "1) Single calculation\n"
           "2) Research series of calculation\n");

    unsigned char mode = UCHAR_MAX;
    do {
      scanf("%hhd", &mode);
      if (mode > 2) { printf("Choose correct option, please\n"); }
    } while (mode > 2);

    if (mode == 0) { return EXIT_SUCCESS; }

    printf("Choose function:\n"
           "0) Back\n"
           "1) sin\n"
           "2) cos\n"
           "3) exp\n"
           "4) sec\n");

    unsigned char choosed_function_index = UCHAR_MAX;
    do {
      scanf("%hhd", &choosed_function_index);
      if (choosed_function_index > 4) { printf("Choose correct option, please\n"); }
    } while (choosed_function_index > 4);

    if (choosed_function_index == 0) { continue; }

    printf("Argument: ");
    double function_argument = 0;
    scanf("%lf", &function_argument);
    if (mode == 1) {
      single_calculation(functions[choosed_function_index - 1], function_argument,
                         standards[choosed_function_index - 1](function_argument));
    } else {
      series_of_calculations(
          functions[choosed_function_index - 1], function_argument,
          standards[choosed_function_index - 1](function_argument));
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
