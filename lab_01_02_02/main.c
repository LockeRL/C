/*
Сидоров Максим ИУ7-22Б
Вариант 2
Программа предназначена для вычисления периметра треугольника
Входные данные: координаты трёх вершин треугольника
Выходные данные: периметр треугольника
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
	double x1, y1;
	double x2, y2;
	double x3, y3;
	double side1, side2, side3;
	double p;
	const double eps = 1e-6;

	printf("Enter coordinates of the first vertex");	
	if (scanf("%lf%lf", &x1, &y1) != 2)
	return EXIT_FAILURE;
	printf("Enter coordinates of the second vertex");
	if (scanf("%lf%lf", &x2, &y2) != 2)
	return EXIT_FAILURE;
	printf("Enter coordinates of the third vertex");
	if (scanf("%lf%lf", &x3, &y3) != 2)
	return EXIT_FAILURE;

	if (fabs(x1 - x2) < eps && fabs(x3 - x2) < eps)
	return EXIT_FAILURE;

	if (fabs(y1 - y2) < eps && fabs(y3 - y2) < eps)
	return EXIT_FAILURE;
		
	side1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (side1 < eps) 
	return EXIT_FAILURE;
	
	side2 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
	if (side2 < eps) 
	return EXIT_FAILURE;
	
	side3 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	if (side3 < eps) 
	return EXIT_FAILURE;
	
	p = side1 + side2 + side3;
	printf("Perimeter: %0.6lf\n", p);
	
	return EXIT_SUCCESS;
}

