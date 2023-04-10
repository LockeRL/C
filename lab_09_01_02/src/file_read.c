#include "../inc/file_read.h"

int open_file(FILE **f, const char *file_name);
bool get_double(double *result, FILE *f);
bool get_name(char **s, FILE *f);
int read_item(item *a, FILE *f);

int copy_array_from_file(item_arr *a, int max_size, const char *file_name)
{
    int return_code = OK;

    FILE *f = NULL;
    return_code = open_file(&f, file_name);

    if (return_code)
        return return_code;

    item buf = init_item();
    int read_num;
    for (a->n = 0; (read_num = read_item(&buf, f)) != 0 && a->n < max_size; a->n++)
    {
        if (read_num == 3)
        {
            a->arr = realloc(a->arr, (a->n + 1) * sizeof(item));
            a->arr[a->n] = buf;
        }
        else
        {
            return_code = DATA_ERROR;
            a->n--;
            free_item(&buf);
        }
    }
    fclose(f);
    free_item(&buf);

    if (a->n == max_size && read_num == 3)
        return_code = OVERFLOW;

    return return_code;
}

int read_item(item *a, FILE *f)
{
    int fields_read = 0;
    char *name = NULL;
    double buf;

    if (get_name(&name, f))
        fields_read++;
    a->name = name;

    if (get_double(&buf, f))
        fields_read++;
    a->weight = buf;

    if (get_double(&buf, f))
        fields_read++;
    a->volume = buf;
    return fields_read;
}

bool get_name(char **s, FILE *f)
{
    size_t len = 0;
    ssize_t rc = getline(s, &len, f);
    if (rc - 1 > STR_LEN || rc <= 1)
    {
        put_zero(*s, 0);
        return false;
    }
    else
        put_zero(*s, rc - 1);
    return true;
}

bool get_double(double *result, FILE *f)
{
    char *buf = NULL;
    char *endptr;
    size_t len = 0;
    ssize_t rc = getline(&buf, &len, f);
    *result = 0.0;
    bool return_code = false;
    if (rc != (ssize_t)-1)
    {
        *result = strtod(buf, &endptr);
        return_code = *result > 0.0 && errno != ERANGE;
    }

    free(buf);

    return return_code;
}


int open_file(FILE **f, const char *file_name)
{
    int return_code = OK;
    *f = fopen(file_name, "r");

    if (*f == NULL)
        return_code = errno;

    return return_code;
}
