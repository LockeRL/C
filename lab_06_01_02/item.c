#include "item.h"

void sort(item arr[], size_t n);
void array_print(const item a[], size_t n);
int open_file(FILE **f, const char *file_name);
double get_double(int *item_read, FILE *f);
int get_name(item *a, FILE *f);
int read_item(item *a, FILE *f);

void sort_and_print(item a[], size_t n)
{
    sort(a, n);
    array_print(a, n);
}

int copy_array_from_file(item arr[], size_t *n, size_t max_size, const char *file_name)
{
    item a;
    *n = 0;
    int read_num;
    int return_code = OK;

    FILE *f = NULL;
    return_code = open_file(&f, file_name);
    
    if (return_code)
        return return_code;
	
    while ((read_num = read_item(&a, f)) != 0 && *n <= max_size)
    {
        if (read_num != 3)
            return_code = DATA_ERROR;
        else if (*n == max_size)
        {
            return_code = OVERFLOW;
            (*n)++;
        }
        else
            arr[(*n)++] = a;
    }
    
    fclose(f);

    return return_code;
}

int read_item(item *a, FILE *f)
{
    int fields_read = get_name(a, f);

    a->weight = get_double(&fields_read, f);

    a->volume = get_double(&fields_read, f);

    return fields_read;
}

int get_name(item *a, FILE *f)
{
    char name[STR_LEN + 2];

    if (fgets(name, sizeof(name), f))
    {
        if (strlen(name) > STR_LEN || strlen(name) <= 1)
            strcpy(a->name, "\0");
        else
        {
            name[strlen(name) - 1] = '\0';
            strcpy(a->name, name);
            return 1;
        }
    }
    return 0;
}

double get_double(int *item_read, FILE *f)
{
    char buf[STR_LEN];
    char *endptr;
    double result = 0.0;
    if (fgets(buf, sizeof(buf), f) != NULL)
    {
        result = strtod(buf, &endptr);
        if (result < 1e-15 || errno == ERANGE)
            result = 0.0;
        else
            (*item_read)++;
    }
    return result;
}

bool starts_with_substr(const item *a, const char *s)
{
    return strstr(a->name, s) == a->name;
}

double density(item *a)
{
    return a->weight / a->volume;
}

void sort(item arr[], size_t n)
{
    double dens_arr[ARR_LEN];

    for (size_t i = 0; i < n; i++)
        dens_arr[i] = density(&arr[i]);
    
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n - i - 1; j++)
            if (dens_arr[j] > dens_arr[j + 1])
            {
                item buf = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = buf;
                
                double buf_dens = dens_arr[j];
                dens_arr[j] = dens_arr[j + 1];
                dens_arr[j + 1] = buf_dens;
            }
}

void item_print(const item *a)
{
    printf("%s\n%lf\n%lf\n", a->name, a->weight, a->volume);
}

void array_print(const item a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        item_print(&a[i]);
}

int open_file(FILE **f, const char *file_name)
{
    int return_code = OK;
    *f = fopen(file_name, "r");

    if (*f == NULL)
        return_code = errno;

    return return_code;
}

void array_print_by_str(const item a[], size_t n, const char *substr)
{
    for (size_t i = 0; i < n; i++)
        if (starts_with_substr(&a[i], substr))
            item_print(&a[i]);
}
