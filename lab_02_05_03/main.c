#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#define NMAX 1024
#define N 10

int min(const int a, const int b)
{
	if (a < b)
		return a;
	return b;
}

int calculate_expression(const int *pb, const int *pe)
{
	int current_element = *pb;
	pb++;
	int result = current_element * *pb;
	// больше 1, чтобы внутри цикла мы могли передвинуть указатель 
	// и не выйти за массив
	while (pe - pb > 1)
	{
		current_element = *pb;
		pb++;
		result = min(result, current_element * *pb);
	}
	return result;
}

bool array_input(int *pb, int *pe)
{
	for (int *pcur = pb; pcur < pe; pcur++)
		if (scanf("%d", pcur) != 1)
			return false;
	return true;
}

int main(void)
{
	int a[NMAX];
	size_t n;
	
	printf("Enter the number of elements: ");
	if (scanf("%zu", &n) != 1 || n > N || n < 2)
	{
		printf("Error: wrong length\n");
		return EXIT_FAILURE;
	}
	
	printf("Enter the elements: ");
	if (!array_input(a, a + n))
	{
		printf("Error: wrong element\n");
		return EXIT_FAILURE;
	}
	
	printf("%d\n", calculate_expression(a, a + n));
	
	return EXIT_SUCCESS;
}
