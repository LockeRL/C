#include "../inc/check_main.h"

int compare_item_arr(item_arr *a, item_arr *b)
{
    if (a->n != b->n)
        return ERROR;

    for (int i = 0; i < a->n; i++)
    {
        if (fabs(a->arr[i].volume - a->arr[i].volume) > 1e-15)
            return ERROR;

        if (fabs(a->arr[i].weight - a->arr[i].weight) > 1e-15)
            return ERROR;

        if (strcmp(a->arr[i].name, b->arr[i].name) != 0)
            return ERROR;
    }

    return OK;
}

Suite *tests_suite()
{
    Suite *s = suite_create("tests");

    s = sort_suite(s);

    return s;
}

int main(void)
{
    Suite *s = tests_suite();

    SRunner *runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    int mistakes = srunner_ntests_failed(runner);

    srunner_free(runner);
    runner = NULL;
    s = NULL;

    return mistakes;
}