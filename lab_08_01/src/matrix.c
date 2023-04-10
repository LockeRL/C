#include "../inc/matrix.h"

matrix init_matrix(void)
{
    matrix a;
    a.mat = NULL;
    a.n = 0;
    a.m = 0;
    a.power = 0;
    return a;
}

void free_matrix_p(int **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(a[i]);
        a[i] = NULL;
    }
    free(a);
    a = NULL;
}

void free_matrix(matrix *a)
{
    free_matrix_p(a->mat, a->n);
    a->n = 0;
    a->m = 0;
    a->power = 0;
}

int **get_pi(int **a, int i)
{
    return &(a[i]);
}

int alloc_matrix(matrix *a, int n, int m)
{
    a->n = n;
    a->m = m;
    a->mat = calloc(n, sizeof(int*));

    if (!a->mat)
        return MEMORY_ERROR;

    int rc = OK;
    for (int i = 0; rc == OK && i < n; i++)
    {
        *get_pi(a->mat, i) = NULL;
        *get_pi(a->mat, i) = calloc(m, sizeof(int));
        if (!*get_pi(a->mat, i))
        {
            free_matrix_p(a->mat, i);
            rc = MEMORY_ERROR;
        }
    }
    return rc;
}

int *get_element(int **a, int i, int j)
{
    return &(a[i][j]);
}

void free_a_b(matrix *a, matrix *b)
{
    free_matrix(a);
    free_matrix(b);
}