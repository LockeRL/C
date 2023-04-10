#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#define NMAX 1024
#define N 10

void array_print(const int a[], const size_t n)
{
	for (size_t i = 0; i < n; i++)
		printf("%d\n", a[i]);
}

void bubble_sort(int a[], const size_t n)
{
	int buff;
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n - 1; j++)
			if (a[j] > a[j + 1])
			{
				buff = a[j + 1];
				a[j + 1] = a[j];
				a[j] = buff;
			}
}

bool array_input(int a[], size_t *n)
{
	*n = 0;
	
	while (scanf("%d", &a[*n]) == 1 && *n <= N)
	{
		*n = *n + 1;
	}
	
	return *n != 0;
}

int main(void)
{
	int a[NMAX];
	size_t n;
	
	printf("Enter the elements: ");
	if (!array_input(a, &n))
	{
		printf("Error: array is empty\n");
		return EXIT_FAILURE;
	}
	
	if (n == 11)
	{
		bubble_sort(a, n - 1);
		printf("Result: ");
		array_print(a, n - 1);
		return 100;
	}
	
	bubble_sort(a, n);
	
	printf("Result: ");
	array_print(a, n);
	
	return EXIT_SUCCESS;
}
