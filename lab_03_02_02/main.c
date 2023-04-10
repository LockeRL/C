#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>

#define NMAX_MATRIX 64
#define N 10

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

int summ_of_digits(const int a)
{
	int num = abs(a);
	int summ = 0;
	while (num != 0)
	{
		summ += num % 10;
		num /= 10;
	}
	return summ;
}

void insert_line(int a[NMAX_MATRIX][NMAX_MATRIX], size_t *n, const size_t k, const size_t pos)
{
	for (size_t i = *n; i > pos; i--)
		for (size_t j = 0; j < k; j++)
			a[i][j] = a[i - 1][j];
			
	for (size_t j = 0; j < k; j++)
		a[pos][j] = -1;
	*n = *n + 1;
}

void make_by_key(int a[NMAX_MATRIX][NMAX_MATRIX], size_t *n, const size_t k)
{
	int counter;
	for (size_t i = 0; i < *n; i++)
	{
		counter = 0;
		for (size_t j = 0; j < k; j++)
		{
			if (summ_of_digits(a[i][j]) % 2 == 1)
				counter++;
			if (counter == 2)
				break;
		}
		if (counter == 2)
		{
			insert_line(a, n, k, i);
			i++;
		}
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
	
	printf("Enter the elements: ");
	if (!matrix_input(a, n, k))
	{
		printf("Error: wrong element\n");
		return EXIT_FAILURE;
	}
	
	make_by_key(a, &n, k);
	
	printf("Result: ");
	matrix_print(a, n, k);
	
	return EXIT_SUCCESS;
}
