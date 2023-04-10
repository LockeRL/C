#include "../inc/array.h"

int **get_pb_add(arr *a)
{
    return &(a->pb);
}

int **get_pe_add(arr *a)
{
    return &(a->pe);
}

void arr_to_null(arr *a)
{
    a->pb = NULL;
    a->pe = NULL;
}

void free_arr(arr *a)
{
    free(*get_pb_add(a));
    arr_to_null(a);
}

int alloc_arr(arr *a, int n)
{
    a->pb = calloc(n, sizeof(int));
    if (!a->pb)
        return 0;
    a->pe = a->pb + n;
    return 1;
}

int open_file(FILE **f, const char *file_name, const char *mode)
{
    int return_code = OK;
    *f = fopen(file_name, mode);

    if (*f == NULL)
        return_code = errno;

    return return_code;
}

int num_count(FILE *f)
{
    int buf;
    int n;
    for (n = 0; fscanf(f, "%d", &buf) == 1; n++);

    if (!feof(f))
        return 0;
    return n;
}

void fill_arr(arr *a, FILE *f)
{
    rewind(f);

    for (int *pb = a->pb; pb < a->pe; pb++)
        if (fscanf(f, "%d", pb) != 1)
            return;
}

int file_read(arr *a, const char *file_name)
{
    FILE *f = NULL;
    int return_code = open_file(&f, file_name, "r");

    if (return_code)
        return return_code;

    int n = num_count(f);
    if (n == 0)
        return DATA_ERROR;

    a->pb = calloc(n, sizeof(int));
    if (a->pb)
    {
        a->pe = a->pb + n;
        fill_arr(a, f);
    }
    else
        return_code = ALLOC_ERROR;
    fclose(f);
    return return_code;
}

int file_write(arr *a, const char *file_name)
{
    FILE *f = NULL;
    int return_code = open_file(&f, file_name, "w");
    if (return_code)
        return return_code;

    for (const int *cur = a->pb; cur < a->pe; cur++)
        fprintf(f, "%d ", *cur);
    fclose(f);
    return OK;
}

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

int new_arr_size(const int *pb_src, const int *pe_src)
{
    int n = 0;
    for (const int *cur = pb_src; cur < pe_src; cur++)
        if (*cur < 0)
            n = cur - pb_src;

    if (n == 0 && *pb_src >= 0)
        n = pe_src - pb_src;

    return n;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (pe_src == NULL || pb_src == NULL || pb_dst == NULL || pe_dst == NULL || pe_src <= pb_src || pb_dst == pe_dst)
        return DATA_ERROR;

    for (int *cur_dst = *pb_dst, *cur_src = (int*)pb_src; cur_dst < *pe_dst; cur_dst++, cur_src++)
        *cur_dst = *cur_src;

    return 0;
}

int copy_by_key(arr *src, arr *dst)
{
    int n = new_arr_size(*get_pb_add(src), *get_pe_add(src));
    if (n == 0)
        return EMPTY_ARRAY_ERROR;

    if (!alloc_arr(dst, n))
        return ALLOC_ERROR;

    return key(*get_pb_add(src), *get_pe_add(src), get_pb_add(dst), get_pe_add(dst));
}