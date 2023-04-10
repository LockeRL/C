/*
Сидоров Максим ИУ7-22Б
Вариант 0
Программа предназначена для вычисления степени числа
Входные данные: основание и степень
Выходные данные: число в нужной степени
*/

#include<stdio.h>
#include<stdlib.h>

// Возведение числа в степень
int power(const int a, const int n)
{
	int result = 1;

	for (int i = 0; i < n; ++i)
		result *= a;

	return result;
}

int main(void)
{
	int a;
	int n;
	int result;
	
	printf("Enter the base: ");
	if (scanf("%d", &a) != 1)
	return EXIT_FAILURE;
	
	printf("Enter the indicator: ");
	if (scanf("%d", &n) != 1 || n <= 0)
	return EXIT_FAILURE;

	result = power(a, n);
	printf("Result: %d\n", result);

	return EXIT_SUCCESS;
}
