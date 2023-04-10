#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>

#define NMAX_MATRIX 64
#define NMAX_ARRAY 1024
#define N 10

void swap_lines(int a[NMAX_MATRIX][NMAX_MATRIX], const size_t n, \
const int buff[NMAX_ARRAY], const size_t pos)
{
	for (size_t i = 0; i < n; i++)
	{
		a[pos + 1][i] = a[pos][i];
		a[pos][i] = buff[i];
	}
}

void bubble_sort_lines(int a[NMAX_MATRIX][NMAX_MATRIX], const size_t n, const size_t k)
{
	int buff[NMAX_ARRAY];
	int comp_prev, comp_cur;
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n - 1; j++)
		{
			comp_prev = comp_cur = 1;
			for (size_t l = 0; l < k; l++)
			{
				comp_prev *= a[j][l];
				comp_cur *= a[j + 1][l];
			}
			if (comp_prev > comp_cur)
			{
				for (size_t m = 0; m < k; m++)
					buff[m] = a[j + 1][m];
				swap_lines(a, k, buff, j);
			}
		}		
}

bool matrix_input(int a[NMAX_MATRIX][NMAX_MATRIX], const size_t n, const size_t k)
{
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < k; j++)
			if (scanf("%d", &a[i][j]) != 1)
				return false;
	return true;
}

void matrix_print(int a[NMAX_MATRIX][NMAX_MATRIX], const size_t n, const size_t k)
{
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < k; j++)
			printf("%d\n", a[i][j]);
}

int main(void)
{
	int a[NMAX_MATRIX][NMAX_MATRIX];
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
	
	bubble_sort_lines(a, n, k);
	
	printf("Result: ");
	matrix_print(a, n, k);
	
	return EXIT_SUCCESS;
}
