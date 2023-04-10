#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "my_constants.h"
#include "my_string.h"

int main(void)
{
	char s1[MAX_STRING_LEN + 1];
	char s2[MAX_STRING_LEN + 1];
	char s1_words[MAX_WORD_COUNT][MAX_WORD_LEN + 1];
	char s2_words[MAX_WORD_COUNT][MAX_WORD_LEN + 1];
	char uniq_words[MAX_WORD_COUNT][MAX_WORD_LEN + 1];
	size_t s1_word_count;
	size_t s2_word_count;
	size_t uniq_word_count;
	
	if (input_string(s1) == 0) 
		return EXIT_FAILURE;
	if (input_string(s2) == 0) 
		return EXIT_FAILURE;
	
	s1_word_count = str_split_words(s1, s1_words);
	if (s1_word_count > MAX_WORD_COUNT || s1_word_count == 0)
		return EXIT_FAILURE;
	s2_word_count = str_split_words(s2, s2_words);
	if (s2_word_count > MAX_WORD_COUNT || s1_word_count == 0)
		return EXIT_FAILURE;
	copy_uniq_words(s1_words, s1_word_count, uniq_words, &uniq_word_count);
	
	printf("Result: ");
	make_pairs(uniq_words, uniq_word_count, s2_words, s2_word_count);
	return EXIT_SUCCESS;
}
