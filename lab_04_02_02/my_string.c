#ifndef MY_STRING_H
#include "my_string.h"
#define MY_STRING_H
#endif

size_t input_string(char *s)
{
	int ch;
	size_t i = 0;
	while ((ch = getchar()) != '\n' && ch != EOF)
		if (i < MAX_STRING_LEN)
		{
			s[i] = ch;
			i++;
		}
	s[i] = '\0';
	return i;
}

bool is_separate_symbol(const char a)
{
	return a == ' ' || a == ',' || a == '.' || a == ';' || a == ':' || a == '-' || a == '!' || a == '?';
}

size_t str_split_words(const char *s, char dst[][MAX_WORD_LEN + 1])
{
	size_t word_count = 0;
	size_t pos = 0;
	size_t word_pos = 0;
	bool in_word = false;
	while (s[pos] != '\0')
	{
		if (!is_separate_symbol(s[pos]))
		{
			in_word = true;
			dst[word_count][word_pos] = s[pos];
			word_pos++;
		}
		else
		{
			if (in_word)
			{
				dst[word_count][word_pos] = '\0';
				word_count++;
			}
			in_word = false;
			word_pos = 0;
		}
		pos++;
		if (word_pos == MAX_WORD_LEN)
			return MAX_WORD_COUNT + 1;
	}
	if (in_word)
	{
		dst[word_count][word_pos] = '\0';
		word_count++;
	}
	return word_count;
}

void word_add(char dst[][MAX_WORD_LEN + 1], size_t *len, const char *word)
{
	size_t i = 0;
	while (word[i] != '\0')
	{
		dst[*len][i] = word[i];
		i++;
	}
	dst[*len][i] = '\0';
	(*len)++;
}

void copy_uniq_words(char src[][MAX_WORD_LEN + 1], const size_t src_word_count, char dst[][MAX_WORD_LEN + 1], size_t *dst_word_count)
{
	*dst_word_count = 0;
	bool uniq;
	for (size_t i = 0; i < src_word_count; i++)
	{
		uniq = true;
		for (size_t j = 0; j < *dst_word_count; j++)
			if (strcmp(src[i], dst[j]) == 0)
			{
				uniq = false;
				break;
			}
		if (uniq)
			word_add(dst, dst_word_count, src[i]);
	}
}

void make_pairs(char s1_words[][MAX_WORD_LEN + 1], const size_t s1_word_count, char s2_words[][MAX_WORD_LEN + 1], const size_t s2_word_count)
{
	bool contains;
	for (size_t i = 0; i < s1_word_count; i++)
	{
		contains = false;
		for (size_t j = 0; j < s2_word_count; j++)
			if (strcmp(s1_words[i], s2_words[j]) == 0)
			{
				contains = true;
				break;
			}
		if (contains)
			printf("%s yes\n", s1_words[i]);
		else
			printf("%s no\n", s1_words[i]);	
	}
}

