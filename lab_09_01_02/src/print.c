#include "../inc/print.h"

void item_print(const item *a)
{
    printf("%s\n%lf\n%lf\n", a->name, a->weight, a->volume);
}

void array_print(const item_arr *a)
{
    for (int i = 0; i < a->n; i++)
        item_print(&a->arr[i]);
}

void sort_and_print(item_arr *a)
{
    double *dens_arr = create_dens_arr(a);

    if (!dens_arr)
        return;

    sort_by_density(a, dens_arr);
    free(dens_arr);

    array_print(a);
}

void array_print_by_str(const item_arr *a, const char *substr)
{
    for (int i = 0; i < a->n; i++)
        if (starts_with_substr(get_item_name(&a->arr[i]), substr))
            item_print(&a->arr[i]);
}