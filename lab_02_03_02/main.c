#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#define NMAX 1024
#define N 10

bool is_square(const int number)
{
	for (int i = 1; i <= number / 2 + 1; i++)
	{
		if (i * i == number)
			return true;
		if (i * i > number)
			return false;
	}
	return false;
}

void delete(int a[], size_t *n, const size_t pos)
{
	for (size_t i = pos; i < *n - 1; i++)
		a[i] = a[i + 1];
	*n = *n - 1;
}

bool delete_squares(int a[], size_t *n)
{
	size_t i = 0;
	while (i < *n)
	{
		if (is_square(a[i]))
			delete(a, n, i);
		else
			i++;
	}
	return *n != 0;
}

void array_print(const int a[], const size_t n)
{
	for (size_t i = 0; i < n; i++)
		printf("%d\n", a[i]);
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
	
	if (!delete_squares(a, &n))
	{
		printf("Error: array is empty\n");
		return EXIT_FAILURE;
	}
	
	printf("Result: ");
	array_print(a, n);
	
	return EXIT_SUCCESS;
}
