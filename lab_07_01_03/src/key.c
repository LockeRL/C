#include "../inc/key.h"

int new_arr_size(const int *pb_src, const int *pe_src)
{
    int n = 0;
    const int *cur = NULL;
    for (cur = pb_src; cur < pe_src; cur++)
        if (*cur < 0)
            n = cur - pb_src;

    if (n == 0)
    {
        if (*pb_src < 0)
            n = 0;
        else
            n = pe_src - pb_src;
    }
    return n;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (pe_src == NULL || pb_src == NULL || pb_dst == NULL || pe_dst == NULL || pe_src <= pb_src || pb_dst == pe_dst)
        return -1;

    int n = new_arr_size(pb_src, pe_src);
    if (n == 0)
        return -1;

    *pb_dst = calloc(n, sizeof(int));
    if (!*pb_dst)
        return -1;

    *pe_dst = *pb_dst + n;

    for (int *cur_dst = *pb_dst, *cur_src = (int*)pb_src; cur_dst < *pe_dst; cur_dst++, cur_src++)
        *cur_dst = *cur_src;

    return 0;
}
