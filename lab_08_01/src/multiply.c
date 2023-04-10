#include "../inc/multiply.h"


void copy(matrix *dst, matrix *src)
{
    for (int i = 0; i < dst->n; i++)
        for (int j = 0; j < dst->m; j++)
            *get_element(dst->mat, i, j) = *get_element(src->mat, i, j);
}

void multiply(matrix *a, matrix *b, matrix *res)
{
    for (int i = 0; i < res->n; i++)
        for (int j = 0; j < res->m; j++)
        {
            *get_element(res->mat, i, j) = 0;
            for (int k = 0; k < res->n; k++)
                *get_element(res->mat, i, j) += *get_element(a->mat, i, k) * *get_element(b->mat, k, j);
        }
}

void multiply_n_times(matrix *tmp, matrix *res, matrix *a)
{
    for (int i = 0; i < a->power; i++)
    {
        multiply(tmp, a, res);
        copy(tmp, res);
    }
}

void init_tmp(matrix *tmp)
{
    for (int i = 0; i < tmp->n; i++)
        *get_element(tmp->mat, i, i) = 1;
}

int calc_multiply_result(matrix *a, matrix *b, matrix *res)
{
    if (alloc_matrix(res, a->n, a->m))
        return MEMORY_ERROR;

    matrix tmp = init_matrix();
    if (alloc_matrix(&tmp, a->n, a->m))
        return MEMORY_ERROR;

    init_tmp(&tmp);
    init_tmp(res);
    multiply_n_times(&tmp, res, a);

    multiply_n_times(&tmp, res, b);

    free_matrix(&tmp);

    return OK;
}