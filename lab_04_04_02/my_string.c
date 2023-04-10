#ifndef MY_STRING_H
#include "my_string.h"
#define MY_STRING_H
#endif

size_t input_string(char *s)
{
	int ch;
	size_t i = 0;
	while ((ch = getchar()) != EOF)
		if (i < MAX_STRING_LEN)
		{
			s[i] = ch;
			i++;
		}
		else
			return MAX_STRING_LEN + 1;
	s[i] = '\0';
	return i;
}

size_t str_split_words(char *s, char words[][MAX_WORD_LEN + 1])
{
	char *pword = strtok(s, "\n \t\r\v\f");
	size_t word_num = 0;
	while (pword)
	{
		if (strlen(pword) > MAX_WORD_LEN)
			return 0;
		size_t i = 0;
		while (pword[i] != '\0')
		{
			words[word_num][i] = pword[i];
			i++;
		}
		words[word_num][i] = '\0';
		word_num++;
		if (word_num > 3)
			return 4;
		pword = strtok(NULL, "\n \t\r\v\f");
	}
	return word_num;
}

bool contains_only_digits(const char *s)
{
	bool is_digit = false;
	for (size_t i = 0; s[i] != '\0'; i++)
	{
		if (is_digit == true)
			is_digit = false;
		for (char j = '0'; j <= '9'; j++)
			if (s[i] == j)
			{
				is_digit = true;
				break;
			}
		if (is_digit == false)
			break;
	}
	return is_digit;
}

int day_from_data(const char *s)
{
	if (!contains_only_digits(s))
		return -1;
	int a = atoi(s);
	if (a > 0 && a <= 31)
		return a;
	return -1;
}

int year_from_data(const char *s)
{
	if (!contains_only_digits(s))
		return -1;
	if (strlen(s) < 4)
		return -1;
	int year = atoi(s);
	if (year < 10000 && year > 0)
		return year;
	return -1;
}

int max_day_from_month(char *data, const char months[12][10])
{
	for (size_t i = 0; data[i] != '\0'; i++)
		data[i] = tolower(data[i]);
	for (size_t i = 0; i < 12; i++)
		if (strcmp(data, months[i]) == 0)
		{
			if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
				return 31;
			else if (i == 3 || i == 5 || i == 8 || i == 10)
				return 30;
			else
				return 29;
		}
	return 0;
}

bool check_data(const int day, const int max_day, const int year)
{
	if (max_day == 29)
	{
		if (year % 4 == 0)
		{
			if ((year % 100 != 0 || year % 400 == 0) && day <= 29)
				return true;
			if (year % 100 == 0 && day <= 28)
				return true;
		}
		if (year % 4 != 0 && day <= 28)
			return true;
	}
	else if (max_day == 31)
		return true;
	else if (max_day >= day)
		return true;
	
	return false;
}

