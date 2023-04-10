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

bool contains_only_separators(const char *s)
{
	for (size_t i = 0; s[i] != '\0'; i++)
		if (s[i] != ' ' && s[i] != '\n' && s[i] != ',' && s[i] != '.' && s[i] != ':' && s[i] != ';' && s[i] != '-' && s[i] != '!' && s[i] != '?')
			return false;
	return true;
}

size_t str_split_words(char *s, char words[][MAX_WORD_LEN + 1])
{
	char *pword = strtok(s, "\n ,.:;-!?");
	size_t word_num = 0;
	while (pword)
	{
		size_t i = 0;
		while (pword[i] != '\0')
		{
			words[word_num][i] = pword[i];
			i++;
		}
		words[word_num][i] = '\0';
		word_num++;
		pword = strtok(NULL, "\n ,.:;-!?");
	}
	return word_num;
}

void insert_word(const char *s, size_t *pos, char *new_s)
{
	size_t i = 1;
	new_s[*pos] = s[0]; 
	(*pos)++;
	while (s[i] != '\0')
	{
		if (s[i] != s[0])
		{
			new_s[*pos] = s[i];
			(*pos)++;
		}
		i++;
	}
}

void make_new_str(char src[][MAX_WORD_LEN + 1], const size_t n, char *new_s)
{
	size_t pos = 0;
	for (size_t i = 0; i < n - 1; i++)
		if (strcmp(src[n - i - 2], src[n - 1]) != 0)
		{
			insert_word(src[n - i - 2], &pos, new_s);
			new_s[pos] = ' ';
			pos++;
		}
	new_s[pos] = '\0';
}

