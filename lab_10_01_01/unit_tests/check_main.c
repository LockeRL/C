#include "../inc/check_main.h"


Suite *tests_suite()
{
    Suite *s = suite_create("tests");

    s = append_suite(s);
    s = find_suite(s);
    s = insert_suite(s);
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