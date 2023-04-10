#ifndef THREE_SIGMA_RULE_H
#define THREE_SIGMA_RULE_H

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool arithmetic_mean(FILE *f, double *mean);
double calculate_sigma_by_mean(FILE *f, const double mean);
int check_numbers(FILE *f, const double sigma, const double mean);

#endif // THREE_SIGMA_RULE_H
