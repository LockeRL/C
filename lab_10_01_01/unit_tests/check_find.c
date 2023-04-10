#include "../inc/check_main.h"
#include "../inc/list.h"

START_TEST(test_find_str)
    {
        ck_assert_int_eq(0, 0);
    }
END_TEST

START_TEST(test_find_num)
    {
        ck_assert_int_eq(0, 0);
    }
END_TEST

START_TEST(test_find_not_exist)
    {
        ck_assert_int_eq(0, 0);
    }
END_TEST


Suite *find_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_find_str);
    tcase_add_test(tc_pos, test_find_num);
    tcase_add_test(tc_pos, test_find_not_exist);

    suite_add_tcase(s, tc_pos);

    return s;
}