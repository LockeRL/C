#include "product.h"

bool file_correct(FILE *f)
{
	fseek(f, 0, SEEK_END);
	long int size = ftell(f);
	return size != 0 && size % sizeof(product_t) == 0;
}

void print_product(product_t a)
{
	printf("%s\n%s\n%" PRIu32 "\n%" PRIu32 "\n", a.name, a.producer, a.price, a.count);
}

int compare_records(product_t a, product_t b)
{
	if (a.price < b.price)
		return 1;
	if (a.price == b.price && a.count < b.count)
		return 1;
	return 0;
}

int get_record_by_pos(FILE *f, const int pos, product_t *record)
{
	fseek(f, pos * sizeof(product_t), SEEK_SET);
	return fread(record, sizeof(product_t), 1, f);
}

void insert_record_by_pos(FILE *f, const int pos, product_t record)
{
	product_t prev, cur;
	prev = record;
	for (int i = pos; get_record_by_pos(f, i, &cur); i++)
	{
		fseek(f, i * sizeof(product_t), SEEK_SET);
		fwrite(&prev, sizeof(product_t), 1, f);
		prev = cur;
	}
	fwrite(&prev, sizeof(product_t), 1, f);
}

void insert_product(FILE *f, product_t rec)
{
	bool flag = false;
	product_t cur;
	int j;
	for (j = 0; get_record_by_pos(f, j, &cur); j++)
	{
		if (compare_records(cur, rec))
		{
			flag = true;
			insert_record_by_pos(f, j, rec);
			break;
		}
	}
	if (!flag)
		insert_record_by_pos(f, j, rec);
}

bool sort_by_price(FILE *f_src, FILE *f_dst)
{
	product_t cur;
	int i;
	for (i = 0; get_record_by_pos(f_src, i, &cur); i++)
		insert_product(f_dst, cur);
	return feof(f_src) && i;
}

bool compare_ends(char *src, char *test)
{
	int len_src = strlen(src);
	int len_test = strlen(test);
	if (len_src > len_test)
		return false;
	for (int i = 0; i < len_src; i++)
		if (src[len_src - i - 1] != test[len_test - i - 1])
			return false;
	return true;
}

bool print_products_by_str(FILE *f, char *s)
{
	product_t cur;
	bool flag = false;
	for (int j = 0; get_record_by_pos(f, j, &cur); j++)
		if (compare_ends(s, cur.name))
		{
			print_product(cur);
			flag = true;
		}
	return flag;
}
