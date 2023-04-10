#include "../inc/check_main.h"

int compare_arrays(const int arr1[], int len1, int arr2[], const int len2)
{
    if (len1 != len2)
        return ERROR;

    for (int i = 0; i < len1; i++)
        if (arr1[i] != arr2[i])
            return ERROR;

    return OK;
}

Suite *tests_suite()
{
    Suite *s = suite_create("tests");

    s = sort_suite(s);
    s = key_suite(s);

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