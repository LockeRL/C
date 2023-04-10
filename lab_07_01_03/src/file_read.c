#include "../inc/file_read.h"

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
