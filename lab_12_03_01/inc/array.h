#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>

#define OK 0
#define DATA_ERROR -1
#define ALLOC_ERROR -2
#define EMPTY_ARRAY_ERROR -3

typedef struct
{
    int *pb;
    int *pe;
} arr;

int **get_pb_add(arr *a);
int **get_pe_add(arr *a);
void free_arr(arr *a);
void arr_to_null(arr *a);
int alloc_arr(arr *a, int n);

int file_read(arr *a, const char *file_name);
int file_write(arr *a, const char *file_name);

void mysort(void *pb, size_t n, size_t size, int (*comp)(const void *, const void *));
int comp(const void *a, const void *b);

int copy_by_key(arr *src, arr *dst);

#endif // ARRAY_H