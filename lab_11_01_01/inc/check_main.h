#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#define TEST_OK 1
#define TEST_ERROR 0

#include <stdio.h>
#include <stdlib.h>  
#include <check.h>
#include "../inc/errors.h"
#include "../inc/my_snprintf.h"


int compare_str(char *s1, char *s2, int len1, int len2);
Suite* my_snprintf_suite(Suite *s);


#endif // CHECK_MAIN_H
