#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>

#define ARR_LEN 15
#define STR_LEN 25

#define OK 0
#define DATA_ERROR -1
#define OPEN_ERROR -3
#define OVERFLOW -2

typedef struct
{
	char name[26];
	double weight;
	double volume;
} item;

int copy_array_from_file(item arr[], size_t *n, size_t max_size, const char *file_name);
void array_print_by_str(const item a[], size_t n, const char *substr);
void sort_and_print(item a[], size_t n);
void array_print(const item a[], size_t n);

#endif // ITEM_H
