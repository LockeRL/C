/*
Сидоров Максим ИУ7-22Б
Вариант 2
Программа предназначена для вычисления значения выражения
Функция: 1/n * (sqrt(1+x1) + ... + sqrt(n+xn))
Входные данные: числа до первого отрицательного
Выходные данные: значение выражения
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
	double x;
	double summ = 0.0;
	double iterator = 1.0;

	if (scanf("%lf", &x) != 1 || x < 0.0)
	return EXIT_FAILURE;

	while (x >= 0.0)
	{
		summ += sqrt(iterator + x);
		iterator += 1.0;
		if (scanf("%lf", &x) != 1)
		return EXIT_FAILURE;
	}

	summ /= (iterator - 1.0);
	
	printf("Value: %0.6lf\n", summ);

	return EXIT_SUCCESS;
}
