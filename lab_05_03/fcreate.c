#include "fcreate.h"

void create_file(FILE *f)
{
	srand(time(NULL));
	int num;	
	for (int i = 0; i < 16; i++)
	{
		num = rand() % 100;
		fwrite(&num, sizeof(int), 1, f);
	}
}
