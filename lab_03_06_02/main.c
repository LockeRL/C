#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>

#define NMAX_MATRIX 64
#define N 10

void matrix_print(int a[NMAX_MATRIX][NMAX_MATRIX], const size_t n, const size_t k)
{
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < k; j++)
			printf("%d\n", a[i][j]);
}

void fill_matrix(int a[NMAX_MATRIX][NMAX_MATRIX], const size_t n, const size_t k)
{
	int num = 1;
	size_t line_pos = n - 1, column_pos = k - 1;
	while (num <= (int)(n * k))
	{
		a[line_pos][column_pos] = num;
		if (num % n == 0)
			column_pos--;
		else if (((num - 1) / (int)n) % 2 == 0)
			line_pos--;
		else
			line_pos++;
		num++;
	}
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
	
	fill_matrix(a, n, k);
	
	printf("Result:\n");
	matrix_print(a, n, k);
	
	return EXIT_SUCCESS;
}
