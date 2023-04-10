#ifndef MY_SNPRINTF_H
#define MY_SNPRINTF_H

#define MAX_NUM_LEN 21

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdarg.h>
#include <limits.h>
#include <math.h>
#include "errors.h"
#include "my_string.h"


int my_snprintf(char *restrict buf, size_t n, char *restrict format, ...);

#endif // MY_SNPRINTF_H
