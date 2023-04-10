#include "../inc/item.h"

double get_volume(const item *a)
{
    return a->volume;
}

double get_weight(const item *a)
{
    return a->weight;
}

char *get_item_name(const item *a)
{
    return (char*)a->name;
}

void free_item(item *a)
{
    free(a->name);
    a->name = NULL;
}

void free_item_arr(item_arr *a)
{
    for (int i = 0; i < a->n; i++)
        free_item(&a->arr[i]);
    free(a->arr);
}

item_arr init_arr()
{
    item_arr a;
    a.n = 0;
    a.arr = NULL;
    return a;
}

item init_item()
{
    item a;
    a.name = NULL;
    return a;
}