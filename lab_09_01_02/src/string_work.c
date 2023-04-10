#include "../inc/string_work.h"

void put_zero(char *s, size_t pos)
{
    s[pos] = '\0';
}

bool starts_with_substr(const char *s, const char *sub)
{
    return strstr(s, sub) == s;
}