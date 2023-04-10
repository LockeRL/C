#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "my_constants.h"
#include "my_string.h"

int main(void)
{
	char s[MAX_STRING_LEN + 1];
	char new_s[MAX_STRING_LEN + 1];
	char words[MAX_WORD_COUNT][MAX_WORD_LEN + 1];
	size_t words_num;
	
	if (input_string(s) == 0)
		return EXIT_FAILURE;
	
	if (contains_only_separators(s))
		return EXIT_FAILURE;
	
	words_num = str_split_words(s, words);
	if (words_num <= 1)
		return EXIT_FAILURE;
	
	make_new_str(words, words_num, new_s);
	
	if (strlen(new_s) == 0)
		return EXIT_FAILURE;
	printf("Result: %s\n", new_s);
	
	return EXIT_SUCCESS;
}
