#include "../inc/my_snprintf.h"
#include "../inc/check_main.h"


START_TEST(test_snprintf_s)
{
	size_t n = 100;
	char *s1 = malloc(n * sizeof(char));
	char *s2 = malloc(n * sizeof(char));
	char *s = "C is good";
	int len1;
	int len2;

	len1 = my_snprintf(s1, n, "True: %s", s);
	len2 = snprintf(s2, n, "True: %s", s);

	int rc = compare_str(s1, s2, len1, len2);
	
	free(s1);
	free(s2);

	ck_assert_int_eq(rc, TEST_OK);
}
END_TEST


START_TEST(test_snprintf_d)
{
    size_t n = 100;
    char *s1 = malloc(n * sizeof(char));
    char *s2 = malloc(n * sizeof(char));
    int a = 576;
    int len1;
    int len2;

    len1 = my_snprintf(s1, n, "True: %d", a);
    len2 = snprintf(s2, n, "True: %d", a);

    int rc = compare_str(s1, s2, len1, len2);

    free(s1);
    free(s2);

    ck_assert_int_eq(rc, TEST_OK);
}
END_TEST


START_TEST(test_snprintf_ld)
{
    size_t n = 100;
    char *s1 = malloc(n * sizeof(char));
    char *s2 = malloc(n * sizeof(char));
    long a = -9324023;
    int len1;
    int len2;

    len1 = my_snprintf(s1, n, "True: %ld", a);
    len2 = snprintf(s2, n, "True: %ld", a);

    int rc = compare_str(s1, s2, len1, len2);

    free(s1);
    free(s2);

    ck_assert_int_eq(rc, TEST_OK);
}
END_TEST


START_TEST(test_snprintf_all)
{
    size_t n = 100;
    char *s1 = malloc(n * sizeof(char));
    char *s2 = malloc(n * sizeof(char));
    long a = -9324023;
    int b = 234;
    char *s = "C is good";
    int len1;
    int len2;

    len1 = my_snprintf(s1, n, "True: %s, %d, %ld", s, b, a);
    len2 = snprintf(s2, n, "True: %s, %d, %ld", s, b, a);

    int rc = compare_str(s1, s2, len1, len2);

    free(s1);
    free(s2);

    ck_assert_int_eq(rc, TEST_OK);
}
END_TEST


Suite* my_snprintf_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_snprintf_s);
    tcase_add_test(tc_pos, test_snprintf_d);
	tcase_add_test(tc_pos, test_snprintf_ld);
	tcase_add_test(tc_pos, test_snprintf_all);
    suite_add_tcase(s, tc_pos);

    return s;
}
