#include "../inc/input_matrix.h"

int input_matrix(matrix *a)
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2 || n <= 0 || m <= 0)
        return SIZE_ERROR;

    int rc = OK;
    if (alloc_matrix(a, n, m))
        rc = MEMORY_ERROR;

    for (int i = 0; rc == OK && i < a->n; i++)
        for (int j = 0; rc == OK && j < a->m; j++)
        {
            if (scanf("%d", get_element(a->mat, i, j)) != 1)
            {
                free_matrix(a);
                rc = DATA_ERROR;
            }
        }

    return rc;
}