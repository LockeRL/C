#include "../inc/check_main.h"

int compare_matrix(matrix *a, matrix *b)
{
    if (a->n != b->n || a->m != b->m)
        return ERROR;

    for (int i = 0; i < a->n; i++)
        for (int j = 0; j < a->m; j++)
            if (a->mat[i][j] != b->mat[i][j])
                return ERROR;

    return OK;
}

Suite *tests_suite()
{
    Suite *s = suite_create("tests");

    s = expand_suite(s);
    s = multiply_suite(s);
    s = square_suite(s);

    return s;
}

int main(void)
{
    Suite *s = tests_suite();

    SRunner *runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    int mistakes = srunner_ntests_failed(runner);

    srunner_free(runner);

    return mistakes;
}