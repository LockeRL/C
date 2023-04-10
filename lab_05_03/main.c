/*
Числа в файле имеют тип int
Чтобы сгенерировать файл стоит запустить программу с аргументом: c <file_name>
Чтобы вывести числа из файла на экран стоит запустить программу с аргументом: p <file_name>
Чтобы отсортировать числа в файле по возрастанию стоит запустить программу с аргументом: s <file_name>
Сортировка осуществляется алгоритмом пузырька
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fcreate.h"
#include "fsort_print.h"

int main(int argc, char **argv)
{
	FILE *f;
	
	if (argc != 3)
		return EXIT_FAILURE;
	
	if (strcmp(argv[1], "c") == 0)
	{
		f = fopen(argv[2], "wb");
		if (f == NULL)
			return EXIT_FAILURE;
		create_file(f);
		fclose(f);
	}
	else if (strcmp(argv[1], "p") == 0)
	{
		f = fopen(argv[2], "rb");
		if (f == NULL)
			return EXIT_FAILURE;
		if (!print_file(f))
		{
			fclose(f);
			return EXIT_FAILURE;
		}
		fclose(f);
	}
	else if (strcmp(argv[1], "s") == 0)
	{
		f = fopen(argv[2], "r+b");
		if (f == NULL)
			return EXIT_FAILURE;
		if (!sort_file(f))
		{
			fclose(f);
			return EXIT_FAILURE;
		}
		fclose(f);
	}
	else
		return EXIT_FAILURE;
	
	
	return EXIT_SUCCESS;
}
