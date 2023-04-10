#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#define NMAX 1024
#define N 10

bool first_digit_equal_last_digit(const int a)
{
	int digit = 0;
	int number = a;
	while (number != 0)
	{
		digit = number % 10;
		number /= 10;
	}
	return digit == (a % 10);
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

bool copy_by_key(const int a[], size_t *n, int new_a[])
{
	size_t counter = 0;
	
	for (size_t i = 0; i < *n; i++)
		if (first_digit_equal_last_digit(a[i]))
		{
			new_a[counter] = a[i];
			counter++;
		}
	
	*n = counter;
	return *n != 0;
}

int main(void)
{
	int a[NMAX];
	int new_a[NMAX];
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
	
	if (!copy_by_key(a, &n, new_a))
	{
		printf("Error: there no such elements\n");
		return EXIT_FAILURE;
	}
	
	printf("Result: ");
	array_print(new_a, n);
	
	return EXIT_SUCCESS;
}
