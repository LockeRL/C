#include "../inc/sort.h"


void swap(void *a, void *b, size_t n)
{
    char *buf = calloc(1, n);
    memmove(buf, a, n);
    memmove(a, b, n);
    memmove(b, buf, n);
    free(buf);
}

double *create_dens_arr(const item_arr *a)
{
    double *dens_arr = calloc(a->n, sizeof(double));
    if (!dens_arr)
        return NULL;
    for (int i = 0; i < a->n; i++)
        dens_arr[i] = get_weight(&a->arr[i]) / get_volume(&a->arr[i]);
    return dens_arr;
}

void sort_by_density(item_arr *a, double *dens_arr)
{
    bool flag = true;
    for (int i = 0; flag && i < a->n; i++)
    {
        flag = false;
        for (int j = 0; j < a->n - i - 1; j++)
            if (dens_arr[j] > dens_arr[j + 1])
            {
                flag = true;
                swap(&a->arr[j], &a->arr[j + 1], sizeof(item));
                swap(&dens_arr[j], &dens_arr[j + 1], sizeof(double));
            }
    }
}