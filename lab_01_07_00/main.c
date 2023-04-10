/*
Сидоров Максим ИУ7-22Б
Вариант 0
Программа предназначена для вычисления степени числа
Функция: f(x)=e^x, s(x)=1+x+x^2/2....
Входные данные: х и точность
Выходные данные: приближенное значение s(x), точное значение f(x),
		 абсолютную и относительную погрешности
*/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

// Высчитывание приближенного значения
double get_maclaurin_s(const double x, const double eps)
{
	double value = 1;
	double element = x;
	int iterator = 1;

	while (fabs(element) > eps)
	{
		value += element;
		iterator++;
		element *= x;
		element /= iterator;
	}
	return value;
}

int main(void)
{
	double x;
	double eps;
	double s;
	double exactvalue;
	double absolut;
	double relative;

	printf("Enter x: ");
	if (scanf("%lf", &x) != 1)
	return EXIT_FAILURE;
	printf("Enter eps: ");
	if (scanf("%lf", &eps) != 1 || eps > 1.0 || eps <= 0.0)
	return EXIT_FAILURE;

	exactvalue = exp(x);
	s = get_maclaurin_s(x, eps);
	absolut = fabs(exactvalue - s);
	relative = absolut / fabs(exactvalue);

	printf("Close value: %0.6lf\n", s);
	printf("Exact value: %0.6lf\n", exactvalue);
	printf("Absolut inaccuracy: %0.6lf\n", absolut);
	printf("Relative inaccuracy: %0.6lf\n", relative);

	return EXIT_SUCCESS;
}
