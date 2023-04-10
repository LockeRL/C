#include "three_sigma_rule.h"

bool arithmetic_mean(FILE *f, double *mean)
{
	*mean = 0.0;
	double num;
	int counter = 0;
	rewind(f);
	while (fscanf(f, "%lf", &num) == 1)
	{
		counter++;
		*mean += num;
	}
	if (!feof(f) || counter == 0)
		return false;
	*mean /= counter;
	return true;
}

double calculate_sigma_by_mean(FILE *f, const double mean)
{
	int counter = 0;
	double num;
	double summ_of_squares = 0.0;
	rewind(f);
	while (fscanf(f, "%lf", &num) == 1)
	{
		counter++;
		summ_of_squares += (num - mean) * (num - mean);
	}
	return sqrt(summ_of_squares / counter);
}

int check_numbers(FILE *f, const double sigma, const double mean)
{
	double num;
	const double eps = 1e-6;
	rewind(f);
	while (fscanf(f, "%lf", &num) == 1)
	{
		if (!((num - mean + sigma) > eps && (mean + sigma - num) > eps))
			return 0;
	}
	return 1;
}

