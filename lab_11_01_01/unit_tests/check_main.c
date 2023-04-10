#include "../inc/check_main.h"


int compare_str(char *s1, char *s2, int len1, int len2)
{
	if ((!strcmp(s1, s2) || (s1 == NULL && s2 == NULL)) && len1 == len2)
		return 1;
	return 0;
}


Suite *tests_suite()
{
	Suite *s = suite_create("tests");

	s = my_snprintf_suite(s);

	return s;
}


int main(void)
{
	Suite *s = tests_suite();
	SRunner *runner = srunner_create(s);
	srunner_run_all(runner, CK_VERBOSE);
	int failed = srunner_ntests_failed(runner);
	srunner_free(runner);

	return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
