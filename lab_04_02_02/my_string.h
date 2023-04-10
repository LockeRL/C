#ifndef LIBRARIES
#define LIBRARIES
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "my_constants.h"
size_t input_string(char *s);
size_t str_split_words(const char *s, char dst[][MAX_WORD_LEN + 1]);
void copy_uniq_words(char src[][MAX_WORD_LEN + 1], const size_t src_word_count, char dst[][MAX_WORD_LEN + 1], size_t *dst_word_count);
void make_pairs(char s1_words[][MAX_WORD_LEN + 1], const size_t s1_word_count, char s2_words[][MAX_WORD_LEN + 1], const size_t s2_word_count);
#endif


