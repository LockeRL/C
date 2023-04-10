#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>

#define NMAX_MATRIX 64
#define NMAX_ARRAY 1024
#define N 10

bool is_prime(const int a)
{
	if (a <= 1)
		return false;
	for (int i = 2; i <= a / 2; i++)
		if (a % i == 0)
			return false;
	return true;
}
void copy_primes(int a[NMAX_MATRIX][NMAX_MATRIX], const size_t n, const size_t k, \
int primes[NMAX_ARRAY], size_t *len)
{
	*len = 0;
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < k; j++)
			if (is_prime(a[i][j]))
			{
				primes[*len] = a[i][j];
				*len = *len + 1;
				a[i][j] = 2;
			}
}

void array_reverse(int a[NMAX_ARRAY], const size_t n)
{
	int buff;
	for (size_t i = 0; i < n / 2; i++)
	{
		buff = a[n - i - 1];
		a[n - i - 1] = a[i];
		a[i] = buff;
	}
}

void insert_primes(int a[NMAX_MATRIX][NMAX_MATRIX], const size_t n, const size_t k, \
int primes[NMAX_ARRAY])
{
	size_t counter = 0;
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < k; j++)
			if (a[i][j] == 2)
			{
				a[i][j] = primes[counter];
				counter++;
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
	int primes[NMAX_ARRAY];
	size_t len;
	
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
	
	copy_primes(a, n, k, primes, &len);
	if (!len)
	{
		printf("Error: there no primes\n");
		return EXIT_FAILURE;
	}
	array_reverse(primes, len);
	insert_primes(a, n, k, primes);
	
	
	printf("Result: ");
	matrix_print(a, n, k);
	
	return EXIT_SUCCESS;
}
