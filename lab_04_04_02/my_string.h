#ifndef LIBRARIES
#define LIBRARIES
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "my_constants.h"
size_t input_string(char *s);
size_t str_split_words(char *s, char words[][MAX_WORD_LEN + 1]);
int day_from_data(const char *s);
int year_from_data(const char *s);
int max_day_from_month(char *data, const char months[12][10]);
bool check_data(const int day, const int max_day, const int year);
#endif


