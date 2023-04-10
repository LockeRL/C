#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdio.h>
#include <stdlib.h>


size_t my_strlen(const char *s);
char *my_strchr(char *s, char ch);
int my_strncat(char *dst, char *src, int num, size_t max_len);
void init_zeros(char *s, size_t n);


#endif // MY_STRING_H
