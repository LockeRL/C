/*
Сидоров Максим ИУ7-22Б
Вариант 2
Программа предназначена для перевода времени в формат часы:минуты:секунды
Входные данные: время в секундах
Выходные данные: время в формате часы минуты секунды
*/

#include<stdlib.h>
#include<stdio.h>

int main(void)
{
	int inputsec;
	int hours, minutes, seconds;
	
	printf("Enter the number of seconds: ");
	if (scanf("%d", &inputsec) != 1)
	return EXIT_FAILURE;

	seconds = inputsec % 60;
	hours = inputsec / 3600;
	minutes = inputsec / 60 - 60 * hours;
	hours %= 24;

	printf("Time: %d ", hours);
	printf("%d ", minutes);
	printf("%d\n", seconds);

	return EXIT_SUCCESS;
}


