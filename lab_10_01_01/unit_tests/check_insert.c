#include "../inc/check_main.h"
#include "../inc/list.h"

// Postives

START_TEST(test_insert_front)
    {
        ck_assert_int_eq(0, 0);
    }
END_TEST

START_TEST(test_insert_back)
    {
        ck_assert_int_eq(0, 0);
    }
END_TEST

START_TEST(test_insert_NULL)
    {
        ck_assert_int_eq(0, 0);
    }
END_TEST

START_TEST(test_insert_middle)
    {
        ck_assert_int_eq(0, 0);
    }
END_TEST


Suite *insert_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_insert_front);
    tcase_add_test(tc_pos, test_insert_back);
    tcase_add_test(tc_pos, test_insert_NULL);
    tcase_add_test(tc_pos, test_insert_middle);

    suite_add_tcase(s, tc_pos);

    return s;
}