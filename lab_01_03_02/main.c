/*
Сидоров Максим ИУ7-22Б
Вариант 2
Программа предназначена для вычисления сопротивления цепи из трех резистров
Входные данные: сопротивления трех резистров
Выходные данные: общее сопротивление параллельного соединения
*/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	double r1, r2, r3;
	double denom;
	double rfull;
	const double eps = 1e-6;
	
	printf("Enter resistances: ");
	if (scanf("%lf%lf%lf", &r1, &r2, &r3) != 3)
	return EXIT_FAILURE;

	denom = r3 * r1 + r2 * r3 + r1 * r2;
	if (denom < eps)
	return EXIT_FAILURE;

	rfull = r1 * r2 * r3 / denom;
	printf("Resistance: %0.6lf\n", rfull);

	return EXIT_SUCCESS;
}


