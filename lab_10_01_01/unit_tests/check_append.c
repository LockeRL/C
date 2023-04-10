#include "../inc/check_main.h"
#include "../inc/list.h"

// Postives

START_TEST(test_append_b_NULL)
{
    ck_assert_int_eq(0, 0);
}
END_TEST

START_TEST(test_append)
    {
        ck_assert_int_eq(0, 0);
    }
END_TEST

START_TEST(test_append_a_NULL)
    {
        ck_assert_int_eq(0, 0);
    }
END_TEST


Suite *append_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_append);
    tcase_add_test(tc_pos, test_append_a_NULL);
    tcase_add_test(tc_pos, test_append_b_NULL);

    suite_add_tcase(s, tc_pos);

    return s;
}