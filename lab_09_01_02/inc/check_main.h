#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <check.h>
#include <stdio.h>
#include <math.h>

#include "item.h"

#define OK 0
#define ERROR -1

int compare_item_arr(item_arr *a, item_arr *b);
Suite *sort_suite(Suite *s);

#endif // CHECK_MAIN_H