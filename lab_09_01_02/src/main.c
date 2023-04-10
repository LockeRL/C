#include <stdlib.h>
#include <string.h>
#include "../inc/item.h"
#include "../inc/print.h"
#include "../inc/file_read.h"

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 3)
        return EXIT_FAILURE;

    item_arr a = init_arr();

    int return_code = copy_array_from_file(&a, ARR_LEN, argv[1]);
    //
    if (return_code)
    {
        free_item_arr(&a);
        return return_code;
    }
    //
    if (a.n == 0)
        return_code = DATA_ERROR;
    else
    {
        if (argc == 2)
            sort_and_print(&a);
        else if (argc == 3 && !strcmp(argv[2], "ALL"))
            array_print(&a);
        else
            array_print_by_str(&a, argv[2]);
    }

    free_item_arr(&a);

    return return_code;
}
