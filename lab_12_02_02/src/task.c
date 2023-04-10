#include "../inc/task.h"

void fib(int *a, int n)
{
    if (n >= 1)
        a[0] = 1;

    if (n >= 2)
        a[1] = 1;

    for (int i = 2; i < n; i++)
        a[i] = a[i - 1] + a[i - 2];
}

bool contains(const int *a, int n, int num)
{
    for (int i = 0; i < n; i++)
        if (a[i] == num)
            return true;
    return false;
}

int make_uniq(int *dst, const int *src, int n)
{
    int uniq = 0;
    for (int i = 0; i < n; i++)
        if (!contains(src, i, src[i]))
        {
            if (dst)
                dst[uniq] = src[i];
            uniq++;
        }

    return uniq;
}