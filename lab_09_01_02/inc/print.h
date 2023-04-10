#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>

#include "item.h"
#include "sort.h"
#include "string_work.h"

void array_print(const item_arr *a);
void sort_and_print(item_arr *a);
void array_print_by_str(const item_arr *a, const char *substr);

#endif // PRINT_H