#include <stdlib.h>
#include <string.h>

#include "../inc/array.h"

int main(int argc, char **argv)
{
    if (argc < 3 || argc > 4)
        return EXIT_FAILURE;

    if (argc == 4 && strcmp(argv[3], "f") != 0)
        return EXIT_FAILURE;

    arr src;
    arr_to_null(&src);
    int return_code = file_read(&src, argv[1]);

    if (return_code)
        return return_code;

    arr dst;
    arr_to_null(&dst);

    if (argc == 4)
    {
        return_code = copy_by_key(&src, &dst);
        free_arr(&src);
    }
    else
        dst = src;

    if (!return_code)
    {
        mysort(*get_pb_add(&dst), *get_pe_add(&dst) - *get_pb_add(&dst), sizeof(int), comp);

        file_write(&dst, argv[2]);
    }

    free_arr(&dst);

    return return_code;
}
