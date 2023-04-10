#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 3)
        return EXIT_FAILURE;

    item a[ARR_LEN];
    size_t n;

    int return_code = copy_array_from_file(a, &n, ARR_LEN, argv[1]);
    //
    if (return_code)
        return return_code;
    //
    if (n == 0)
        return_code = DATA_ERROR;
    else
    {
        if (argc == 2)
            sort_and_print(a, n);
        else if (argc == 3 && !strcmp(argv[2], "ALL"))
            array_print(a, n);
        else
            array_print_by_str(a, n, argv[2]);
    }

    return return_code;
}
