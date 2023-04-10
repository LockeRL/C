/*
Сидоров Максим ИУ7-22Б
Вариант 2
Программа предназначена для циклического сдвига числа на некоторое количество позиций
Входные данные: целое 4-байтное число, количество бит для сдвига
Выходные данные: новое число
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

void convert_to_bits(const uint32_t a, const int n)
{
	int symb;
	
	printf("Result: ");
	for (int i = 31; i >= 0; i--)
	{
		symb = (a >> (i - (n % 32))) % 2;
		printf("%d", symb);
	}
	printf("\n");
}

int main(void)
{
	uint32_t a;
	int n;
	
	printf("Enter the number: ");
	if (scanf("%" SCNu32, &a) != 1)
	{
		printf("Error: wrong number\n");
		return EXIT_FAILURE;
	}
	printf("Enter the number of shifts: ");
	if (scanf("%d", &n) != 1 || n < 0)
	{
		printf("Error: wrong number of shifts\n");
		return EXIT_FAILURE;
	}

	convert_to_bits(a, n);

	return EXIT_SUCCESS;
}
