#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <check.h>
#include <stdio.h>


#define OK 0
#define ERROR -1

int compare_arrays(const int arr1[], int len1, int arr2[], const int len2);
Suite *sort_suite(Suite *s);
Suite *key_suite(Suite *s);

#endif // CHECK_MAIN_H