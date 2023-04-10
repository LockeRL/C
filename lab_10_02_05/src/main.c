#include <stdio.h>

#include "../inc/list.h"
#include "../inc/input.h"
#include "../inc/print.h"

int main()
{
    int command = get_command();

    if (command == -1)
        return EXIT_FAILURE;

    node_t *a = create_list();

    if (a == NULL)
        return EXIT_FAILURE;

    int rc = 0;

    if (command == 1)
    {
        node_t *b = create_list();

        if (b == NULL)
            rc = -1;

        if (rc == 0)
            concatenate(a, b);
    }
    else if (command == 2)
        delete_double_spaces(a);
    else if (command == 3)
    {
        char *str;
        size_t read = get_string(&str);
        if (read <= 1)
            rc = -1;

        int pos = find_str(a, str);
        free_str(&str);

        if (pos == -1)
            rc = -1;

        if (rc != -1)
            printf("%d\n", pos);
    }

    if (rc == 0 && command != 3)
        print_list(a);

    free_list(a);

    return rc;
}
