#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "my_constants.h"
#include "my_string.h"

int main(void)
{
	char s[MAX_STRING_LEN + 1];
	char data[3][MAX_WORD_LEN + 1];
	const char months[12][10] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" }; 
	size_t symb_count;
	int max_day;
	int day;
	int year;
	
	symb_count = input_string(s);
	if (symb_count == (MAX_STRING_LEN + 1))
		return EXIT_FAILURE;
	
	if (symb_count < MIN_STRING_LEN)
	{
		printf("NO\n");
		return EXIT_SUCCESS;
	}
	
	
	
	if (str_split_words(s, data) != 3)
	{
		printf("NO\n");
		return EXIT_SUCCESS;
	}
	
	day = day_from_data(data[0]);
	if (day == -1)
	{
		printf("NO\n");
		return EXIT_SUCCESS;
	}
	
	year = year_from_data(data[2]);
	if (year == -1)
	{
		printf("NO\n");
		return EXIT_SUCCESS;
	}
	
	max_day = max_day_from_month(data[1], months);
	if (max_day == 0)
	{
		printf("NO\n");
		return EXIT_SUCCESS;
	}
	
	if (check_data(day, max_day, year))
		printf("YES\n");
	else
		printf("NO\n");
	
	return EXIT_SUCCESS;
}
