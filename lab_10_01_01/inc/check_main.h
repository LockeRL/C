#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <check.h>
#include <stdio.h>
#include <math.h>

#include "list.h"

Suite *append_suite(Suite *s);
Suite *find_suite(Suite *s);
Suite *insert_suite(Suite *s);
Suite *sort_suite(Suite *s);

#endif // CHECK_MAIN_H