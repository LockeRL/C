#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>

#define NMAX_MATRIX 64
#define N 10

int max(const int a, const int b)
{
	if (a > b)
		return a;
	return b;
}

bool matrix_input(int a[NMAX_MATRIX][NMAX_MATRIX], const size_t n)
{
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n; j++)
			if (scanf("%d", &a[i][j]) != 1)
				return false;
	return true;
}

int max_under_side_diagonal(int a[NMAX_MATRIX][NMAX_MATRIX], const size_t n)
{
	int result = 0;
	int counter = 0;
	for (size_t j = 1; j < n; j++)
		for (size_t i = n - 1; i + j >= n; i--)
			if (abs(a[i][j]) % 10 == 5)
			{
				if (!counter)
				{
					counter++;
					result = a[i][j];
				}
				result = max(result, a[i][j]);
			}
	return result;
}

int main(void)
{
	int a[NMAX_MATRIX][NMAX_MATRIX];
	size_t n, k;
	int result;
	
	printf("Enter the number of lines: ");
	if (scanf("%zu", &n) != 1 || n > N || n < 2)
	{
		printf("Error: wrong number of lines\n");
		return EXIT_FAILURE;
	}
	
	printf("Enter the number of columns: ");
	if (scanf("%zu", &k) != 1 || k > N || k != n)
	{
		printf("Error: wrong number of lines\n");
		return EXIT_FAILURE;
	}
	
	printf("Enter the elements: ");
	if (!matrix_input(a, n))
	{
		printf("Error: wrong element\n");
		return EXIT_FAILURE;
	}
	
	result = max_under_side_diagonal(a, n);
	if (!result)
	{
		printf("Error: no such elements\n");
		return EXIT_FAILURE;
	}
	
	printf("Result: %d\n", result);
	
	return EXIT_SUCCESS;
}
