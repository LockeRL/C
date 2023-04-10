#include "../inc/my_string.h"

size_t my_strlen(const char *s)
{
    if (s == NULL)
        return 0;

    size_t i = 0;
    for (; s[i] != '\0';)
        i++;

    return i;
}

char *my_strchr(char *s, char ch)
{
    int pos = -1;
    for (size_t i = 0; s && pos == -1 && s[i] != '\0'; i++)
        if (s[i] == ch)
            pos = i;

    return pos == -1 ? NULL : s + pos;
}

int my_strncat(char *dst, char *src, int num, size_t max_len)
{
    size_t j = my_strlen(dst);
    size_t i = 0;

    for (; i < (size_t)num; i++, j++)
        if (dst && max_len != 0 && j < max_len - 1)
            dst[j] = src[i];

    return i;
}

void init_zeros(char *s, size_t n)
{
    for (size_t i = 0; i < n; i++)
        s[i] = '\0';
}
