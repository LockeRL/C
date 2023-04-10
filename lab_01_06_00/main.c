/*
Сидоров Максим ИУ7-22Б
Вариант 0
Программа предназначена для вычисления треугольника
Входные данные: координаты вершин треугольника
Выходные данные: 0-остроугольный, 1-прямоугольный, 2-тупоугольный
*/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

// Возвращает максимум из двух чисел
double max(const double a, const double b)
{
	if (a > b)
		return a;
	else
		return b;
}

// Возвращает минимум из двух чисел
double min(const double a, const double b)
{
	if (a > b)
		return b;
	else
		return a;
}

int main(void)
{
	double x1, y1;
	double x2, y2;
	double x3, y3;
	const double eps = 1e-6;
	double side1, side2, side3;
	double maxside, minside, midside;
	
	printf("Enter coordinates of the first vertex: ");
	if (scanf("%lf%lf", &x1, &y1) != 2)
	return EXIT_FAILURE;
	
	printf("Enter coordinates of the second vertex: ");
	if (scanf("%lf%lf", &x2, &y2) != 2)
	return EXIT_FAILURE;
	
	printf("Enter coordinates of the third vertex: ");
	if (scanf("%lf%lf", &x3, &y3) != 2)
	return EXIT_FAILURE;
	
	if (fabs((x3 - x1) * (y2 - y1) - (x2 - x1) * (y3 - y1)) < eps)
	return EXIT_FAILURE;
	
	side1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	if (!(side1 > 0.0))
	return EXIT_FAILURE;

	side2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
	if (!(side2 > 0.0))
	return EXIT_FAILURE;

	side3 = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
	if (!(side3 > 0.0))
	return EXIT_FAILURE;

	maxside = max(side1, max(side2, side3));
	minside = min(side1, min(side2, side3));
	midside = (side1 + side2 + side3) - maxside - minside;

	if (minside + midside < maxside)
		printf("Type: 2\n");
	else if (minside + midside > maxside)
		printf("Type: 0\n");
	else
		printf("Type: 1\n");

	return EXIT_SUCCESS;
}


