#include "calculations.h"

#include <math.h>

#define NULL_PRECISION 0.00000001


double sec(const double argument) { return 1 / cos(argument); }

// NOLINTNEXTLINE (*swappable-by-mistake)
Calc_result_t my_sin(long double argument, const long double precision,
                     const unsigned short amount_of_terms) {
  argument = fmodl(argument + M_PI, 2 * M_PI) - M_PI;

  long double term         = argument;
  long double result       = term;
  unsigned int term_number = 1;

  while (fabsl(term) > precision && term_number < amount_of_terms) {
    term   *= -(argument * argument) / ((2 * term_number) * (2 * term_number + 1));
    result += term;

    term_number++;
  }

  return (Calc_result_t){result, term_number};
}

// NOLINTNEXTLINE (*swappable-by-mistake)
Calc_result_t my_cos(long double argument, const long double precision,
                     const unsigned short amount_of_terms) {
  argument = fmodl(argument + M_PI, 2 * M_PI) - M_PI;

  long double term   = 1.0;
  long double result = term;
  int term_number    = 0;

  while (fabsl(term) > precision && term_number < amount_of_terms) {
    term *= -(argument * argument) / ((2 * term_number + 1) * (2 * term_number + 2));
    result += term;
    term_number++;
  }

  return (Calc_result_t){result, term_number};
}

// NOLINTNEXTLINE (*swappable-by-mistake)
Calc_result_t my_exp(const long double argument, const long double precision,
                     const unsigned short amount_of_terms) {
  long double result = 0;
  long double term   = 1;
  int term_number    = 0;
  do {
    result += term;
    term   *= (argument / ++term_number);
  } while (term_number < amount_of_terms && term >= precision);

  return (Calc_result_t){result, term_number};
}

// NOLINTNEXTLINE (*swappable-by-mistake)
Calc_result_t my_sec(long double argument, const long double precision,
                     const unsigned short amount_of_terms) {
  argument = fmodl(argument + M_PI, 2 * M_PI) - M_PI;


  Calc_result_t cos_res = my_cos(argument, precision, amount_of_terms);
  return (Calc_result_t){1.0 / cos_res.result, cos_res.amount_of_terms_used};
}
