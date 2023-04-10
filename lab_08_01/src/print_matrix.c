#include "../inc/print_matrix.h"

void print_matrix(matrix *a)
{
    for (int i = 0; i < a->n; i++)
    {
        for (int j = 0; j < a->m; j++)
            printf("%d ", *get_element(a->mat, i, j));
        printf("\n");
    }
}