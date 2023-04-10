#include "fsort_print.h"

size_t len_of_file(FILE *f)
{
	fseek(f, 0, SEEK_END);
	return ftell(f);
}

bool print_file(FILE *f)
{	
	int num;
	int n = len_of_file(f);
	if (n == 0 || n % sizeof(int) != 0)
		return false;
	rewind(f);
	while (fread(&num, sizeof(int), 1, f))
		printf("%d\n", num);
	return feof(f);
}

int get_number_by_pos(FILE *f, const int pos)
{
	int num;
	fseek(f, pos * sizeof(int), SEEK_SET);
	if (fread(&num, sizeof(int), 1, f))
		return num;
	return -1;
}

void put_number_by_pos(FILE *f, const int pos, const int num)
{
	fseek(f, pos * sizeof(int), SEEK_SET);
	fwrite(&num, sizeof(int), 1, f);
}

bool sort_file(FILE *f)
{
	int n = len_of_file(f);
	int cur, prev;
	if (n == 0 || n % sizeof(int) != 0)
		return false;
	n /= sizeof(int);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
		{
			prev = get_number_by_pos(f, j);
			cur = get_number_by_pos(f, j + 1);
			if (cur == -1 || prev == -1)
				return false;
			if (prev > cur)
			{
				put_number_by_pos(f, j + 1, prev);
				put_number_by_pos(f, j, cur);
			}
		}
	return true;
}
