#include "../inc/file_write.h"

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
