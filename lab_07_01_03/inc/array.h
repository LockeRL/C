#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

typedef struct
{
    int *pb;
    int *pe;
} arr;

int **get_pb_add(arr *a);
int **get_pe_add(arr *a);
void free_arr(arr *a);
void arr_to_null(arr *a);

#endif // ARRAY_H