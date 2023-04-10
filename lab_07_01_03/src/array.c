#include "../inc/array.h"

int **get_pb_add(arr *a)
{
    return &(a->pb);
}

int **get_pe_add(arr *a)
{
    return &(a->pe);
}

void arr_to_null(arr *a)
{
    a->pb = NULL;
    a->pe = NULL;
}

void free_arr(arr *a)
{
    free(*get_pb_add(a));
    arr_to_null(a);
}