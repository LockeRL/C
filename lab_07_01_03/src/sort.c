#include "../inc/sort.h"

void swap(void *a, void *b, size_t n)
{
    char buf;
    for (char *ab = a, *bb = b; ab < (char*)a + n; ab++, bb++)
    {
        buf = *ab;
        *ab = *bb;
        *bb = buf;
    }
}

int comp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

void mysort(void *pb, size_t n, size_t size, int (*comp)(const void *, const void *))
{
    bool flag = true;
    for (size_t i = 0; i < n && flag; i++)
    {
        flag = false;
        for (size_t j = 0; j < n - i - 1; j++)
            if (comp((char*)pb + j * size, (char*)pb + (j + 1) * size) > 0)
            {
                flag = true;
                swap((char*)pb + j * size, (char*)pb + (j + 1) * size, size);
            }
    }
}
