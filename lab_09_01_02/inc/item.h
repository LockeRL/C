#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>

#define ARR_LEN 15
#define STR_LEN 25

typedef struct
{
    char *name;
    double weight;
    double volume;
} item;

typedef struct
{
    item *arr;
    int n;
} item_arr;

char *get_item_name(const item *a);
double get_volume(const item *a);
double get_weight(const item *a);

void free_item_arr(item_arr *a);
void free_item(item *a);
item_arr init_arr();
item init_item();

#endif // ITEM_H
