#include <stdio.h>
#include <stdlib.h>
#include "three_sigma_rule.h"

int main(int argc, char **argv)
{
	FILE *f;
	double mean;
	double sigma;
	
	if (argc != 2)
		return EXIT_FAILURE;
	
	f = fopen(argv[1], "r");
	if (f == NULL)
		return EXIT_FAILURE;
	
	if (!arithmetic_mean(f, &mean))
	{
		fclose(f);
		return EXIT_FAILURE;
	}
	
	sigma = calculate_sigma_by_mean(f, mean);
	
	printf("Result: %d\n", check_numbers(f, 3 * sigma, mean));
	
	fclose(f);
	return EXIT_SUCCESS;
}
