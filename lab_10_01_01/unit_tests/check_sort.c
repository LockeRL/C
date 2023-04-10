#include "../inc/check_main.h"
#include "../inc/list.h"

// Postives

START_TEST(test_sort_pos)
    {
        ck_assert_int_eq(0, 0);
    }
END_TEST

START_TEST(test_sort_neg)
    {
        ck_assert_int_eq(0, 0);
    }
END_TEST

START_TEST(test_sort_zeros)
    {
        ck_assert_int_eq(0, 0);
    }
END_TEST

START_TEST(test_sort)
    {
        ck_assert_int_eq(0, 0);
    }
END_TEST


Suite *sort_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_sort_pos);
    tcase_add_test(tc_pos, test_sort_neg);
    tcase_add_test(tc_pos, test_sort_zeros);
    tcase_add_test(tc_pos, test_sort);

    suite_add_tcase(s, tc_pos);

    return s;
}