#ifndef MY_STRING_H
#include "my_string.h"
#define MY_STRING_H
#endif

char *my_strpbrk(const char *s1, const char *s2)
{
	while (*s1 != '\0')
	{
		const char *beg = s2;
		while (*beg != '\0')
		{
			if (*s1 == *beg)
				return (char *)s1;
			beg++;
		}
		s1++;
	}
	return NULL;
}

size_t my_strspn(const char *s1, const char *s2)
{
	const char *s = s1;
	while (*s != '\0')
	{
		const char *beg = s2;
		bool flag = false;
		while (*beg != '\0')
		{
			if (*s == *beg)
				flag = true;
			beg++;
		}
		if (!flag)
			return s - s1;
		s++;
	}
	return s - s1;
}

size_t my_strcspn(const char *s1, const char *s2)
{
	const char *s = s1;
	while (*s != '\0')
	{
		const char *beg = s2;
		bool flag = false;
		while (*beg != '\0')
		{
			if (*s == *beg)
				flag = true;
			beg++;
		}
		if (flag)
			return s - s1;
		s++;
	}
	return s - s1;
}

char *my_strchr(const char *s, int ch) 
{
	while (*s != (char)ch) 
	{
		if (*s == '\0') 
			return NULL;
		s++;
	}
	return (char *)s;
}

char *my_strrchr(const char *s, int ch)
{
	if (ch > 255 || ch < 0)
		return NULL;
		
	char *result = NULL;
	
	if (*s == (char)ch)
		result = (char *)s;
		
	while (*s != '\0')
	{
		s++;
		if (*s == (char)ch)
			result = (char *)s;
	}
	return result;
} 
