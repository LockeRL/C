#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <check.h>
#include <stdio.h>

#include "matrix.h"
#include "print_matrix.h"


#define OK 0
#define ERROR -1

int compare_matrix(matrix *a, matrix *b);
Suite *expand_suite(Suite *s);
Suite *multiply_suite(Suite *s);
Suite *square_suite(Suite *s);

#endif // CHECK_MAIN_H