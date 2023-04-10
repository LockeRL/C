#ifndef UTILITY_H
#define UTILITY_H

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int copy_str(char *dst, const char *src, int n);
ssize_t get_string(char **str);
void free_str(char **s);
int get_command();

#endif // UTILITY_H
