#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "my_string.h"


int main(void)
{
	int fails = 0;
	const char data[5][11] = { "0123456789", "fh2392", "32420cm", "", "9876543210" };
	const char strpbrk_src[5][10] = { "2130", "0123", "fjk9", "6fa", "984" };
	const char strcsp_src[5][10] = { "2130", "3", "fjk34", "g", "984" };
	int strchr_symbol[5] = { '\0', '3', '2', '6', 'd' };
	
	for (size_t j = 0; j < 5; j++)
		for (size_t i = 0; i < 5; i++)
			if (strpbrk(data[j], strpbrk_src[i]) != my_strpbrk(data[j], strpbrk_src[i]))
				fails++;
	for (size_t j = 0; j < 5; j++)
		for (size_t i = 0; i < 5; i++)
			if (strspn(data[j], strcsp_src[i]) != my_strspn(data[j], strcsp_src[i]))
				fails++;
	for (size_t j = 0; j < 5; j++)
		for (size_t i = 0; i < 5; i++)
			if (strcspn(data[j], strcsp_src[i]) != my_strcspn(data[j], strcsp_src[i]))
				fails++;
	for (size_t j = 0; j < 5; j++)
		for (size_t i = 0; i < 5; i++)
			if (strchr(data[j], strchr_symbol[i]) != my_strchr(data[j], strchr_symbol[i]))
				fails++;
	for (size_t j = 0; j < 5; j++)
		for (size_t i = 0; i < 5; i++)
			if (strrchr(data[j], strchr_symbol[i]) != my_strrchr(data[j], strchr_symbol[i]))
				fails++;
				
	printf("Result: %d\n", fails);
	return EXIT_SUCCESS;
}
