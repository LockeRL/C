#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "product.h"

int main(int argc, char **argv)
{
	FILE *f_src;
	FILE *f_dst;
	
	if (argc == 4 && strcmp(argv[1], "sb") == 0)
	{
		f_src = fopen(argv[2], "rb");
		if (f_src == NULL)
			return EXIT_FAILURE;
		f_dst = fopen(argv[3], "wb+");
		if (f_dst == NULL)
		{
			fclose(f_src);
			return EXIT_FAILURE;
		}
		if (strcmp(argv[2], argv[3]) == 0)
		{	
			fclose(f_src);
			fclose(f_dst);
			return EXIT_FAILURE;
		}
		if (!sort_by_price(f_src, f_dst))
		{
			fclose(f_src);
			fclose(f_dst);
			return EXIT_FAILURE;
		}
		fclose(f_src);
		fclose(f_dst);	
	}
	else if (argc == 4 && strcmp(argv[1], "fb") == 0)
	{
		f_dst = fopen(argv[2], "r");
		if (f_dst == NULL)
			return EXIT_FAILURE;
		if (!file_correct(f_dst))
		{
			fclose(f_dst);
			return EXIT_FAILURE;
		}
		if (!print_products_by_str(f_dst, argv[3]))
		{
			fclose(f_dst);
			return EXIT_FAILURE;
		}
		fclose(f_dst);
	}
	else if (argc == 3 && strcmp(argv[1], "ab") == 0)
	{
		f_dst = fopen(argv[2], "rb+");
		if (f_dst == NULL)
			return EXIT_FAILURE;
		product_t rec;
		memset(&rec, 0, sizeof(product_t));
		if (scanf("%s %s %" SCNu32 "%" SCNu32, rec.name, rec.producer, &rec.price, &rec.count) != 4)
			return EXIT_FAILURE;
		insert_product(f_dst, rec);
		fclose(f_dst);	
	}
	else 
		return 53;
		
	return EXIT_SUCCESS;
}
