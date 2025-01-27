#pragma once
#ifndef CALCULATIONS_H
#define CALCULATIONS_H

typedef struct Calc_result {
  long double result;
  unsigned int amount_of_terms_used;
} Calc_result_t;

double sec(double argument);

Calc_result_t my_sin(long double argument, long double precision,
                     unsigned short amount_of_terms);

Calc_result_t my_cos(long double argument, long double precision,
                     unsigned short amount_of_terms);

Calc_result_t my_exp(long double argument, long double precision,
                     unsigned short amount_of_terms);

Calc_result_t my_sec(long double argument, long double precision,
                     unsigned short amount_of_terms);
#endif  // CALCULATIONS_H
