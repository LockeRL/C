#include "../inc/utility.h"

int copy_str(char *dst, const char *src, int n)
{
    int i = 0;
    for (; i < n && src[i] != '\0'; i++)
        dst[i] = src[i];

    if (src[i] == '\0' && i != n)
        dst[i++] = '\0';
    return i;
}

ssize_t get_string(char **str)
{
    *str = NULL;
    size_t len = 0;
    ssize_t read = getline(str, &len, stdin);
    (*str)[read - 1] = '\0';
    return read;
}

/*
 * 0 - out(print)
 * 1 - cat(concatenate)
 * 2 - sps(delete spaces)
 * 3 - pos(find substring)
 * -1 - wrong arg
 */
int check_command(char *s)
{
    if (strcmp(s, "out") == 0)
        return 0;
    if (strcmp(s, "cat") == 0)
        return 1;
    if (strcmp(s, "sps") == 0)
        return 2;
    if (strcmp(s, "pos") == 0)
        return 3;
    return -1;
}

void free_str(char **s)
{
    free(*s);
    *s = NULL;
}

int get_command()
{
    char *str;
    get_string(&str);
    int command = check_command(str);
    free_str(&str);
    return command;
}