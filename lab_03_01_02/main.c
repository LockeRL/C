#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#define NMAX_MATRIX 64
#define NMAX_ARRAY 1024
#define N 10

bool matrix_input(int a[NMAX_MATRIX][NMAX_MATRIX], const size_t n, const size_t k)
{
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < k; j++)
			if (scanf("%d", &a[i][j]) != 1)
				return false;
	return true;
}

void array_print(const int a[NMAX_ARRAY], const size_t n)
{
	for (size_t i = 0; i < n; i++)
		printf("%d\n", a[i]);
}

bool pos_neg_numbers_alternate(const int a, const int b)
{
	return (a > 0 && b < 0) || (a < 0 && b > 0);
}

void make_by_key(int src[NMAX_MATRIX][NMAX_MATRIX], const size_t n, const size_t k, \
int dst[NMAX_ARRAY])
{
	bool alternate_flag;
	if (n == 1)
		for (size_t i = 0; i < k; i++)
			dst[i] = 0;
	else
		for (size_t j = 0; j < k; j++)
		{
			alternate_flag = true;
			for (size_t i = 0; i < n - 1; i++)
				if (!pos_neg_numbers_alternate(src[i][j], src[i + 1][j]))
				{
					alternate_flag = false;
					break;
				}
			if (alternate_flag)
				dst[j] = 1;
			else
				dst[j] = 0;
		}
}

int main(void)
{
	int a[NMAX_MATRIX][NMAX_MATRIX];
	int new_a[NMAX_ARRAY];
	size_t n, k;
	
	printf("Enter the number of lines: ");
	if (scanf("%zu", &n) != 1 || n > N || n < 1)
	{
		printf("Error: wrong number of lines\n");
		return EXIT_FAILURE;
	}
	
	printf("Enter the number of columns: ");
	if (scanf("%zu", &k) != 1 || k > N || k < 1)
	{
		printf("Error: wrong number of columns\n");
		return EXIT_FAILURE;
	}
	
	printf("Enter the elements: ");
	if (!matrix_input(a, n, k))
	{
		printf("Error: wrong element\n");
		return EXIT_FAILURE;
	}
	
	make_by_key(a, n, k, new_a);
	
	printf("Result: ");
	array_print(new_a, k);
	
	return EXIT_SUCCESS;
}
