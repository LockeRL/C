#ifndef STRING_WORK_H
#define STRING_WORK_H

#include <string.h>
#include <stdbool.h>
#include "item.h"

bool starts_with_substr(const char *s, const char *sub);
void put_zero(char *s, size_t pos);

#endif // STRING_WORK_H