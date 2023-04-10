#ifndef PRODUCT_H
#define PRODUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>

typedef struct
{
	char name[31];
	char producer[16];
	uint32_t price;
	uint32_t count;
} product_t;

bool print_products_by_str(FILE *f, char *s);
bool sort_by_price(FILE *f_src, FILE *f_dst);
void insert_product(FILE *f, product_t rec);
bool file_correct(FILE *f);

#endif // PRODUCT_H
