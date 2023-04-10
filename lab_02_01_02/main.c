#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>

#define NMAX 1024
#define N 10

double negative_arithmetic_mean(const int a[], const size_t n)
{
	double summ = 0.0;
	int counter = 0;
	for (size_t i = 0; i < n; i++)
		if (a[i] < 0)
		{
			counter++;
			summ += a[i];
		}
	if (counter == 0)
		return 0.0;
	return summ / (counter * 1.0);
}

bool array_input(int a[], const size_t n)
{
	for (size_t i = 0; i < n; i++)
		if (scanf("%d", &a[i]) != 1)
			return false;
	return true;
}

int main(void)
{
	int a[NMAX];
	size_t n;
	const double eps = 1e-6;
	double result;
	
	printf("Enter the number of elements: ");
	if (scanf("%zu", &n) != 1 || n > N)
	{
		printf("Error: wrong length\n");
		return EXIT_FAILURE;
	}
	
	printf("Enter the elements:");
	if (!array_input(a, n))
	{
		printf("Error: wrong element\n");
		return EXIT_FAILURE;
	}
	
	result = negative_arithmetic_mean(a, n);
	
	if (fabs(result) < eps)
	{
		printf("Error: there are not negative elements\n");
		return EXIT_FAILURE;
	}
	
	printf("Result: %0.6lf\n", result);
	
	return EXIT_SUCCESS;
}
