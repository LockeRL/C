#ifndef LIBRARIES
#define LIBRARIES
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "my_constants.h"
size_t input_string(char *s);
bool contains_only_separators(const char *s);
size_t str_split_words(char *s, char words[][MAX_WORD_LEN + 1]);
void make_new_str(char src[][MAX_WORD_LEN + 1], const size_t n, char *new_s);
#endif


