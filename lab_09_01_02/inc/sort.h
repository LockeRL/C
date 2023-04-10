#ifndef SORT_H
#define SORT_H

#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#include "item.h"

void sort_by_density(item_arr *a, double dens_arr[]);
double *create_dens_arr(const item_arr *a);

#endif // SORT_H