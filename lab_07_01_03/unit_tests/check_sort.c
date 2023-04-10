#include "../inc/sort.h"
#include "../inc/check_main.h"

START_TEST(test_sort_equal_elems)
{
    int src[] = {7, 7, 7, 7, 7};
    int len_src = 5;

    int ans[] = {7, 7, 7, 7, 7};
    int len_ans = 5;

    mysort(src, len_src, sizeof(int), comp);

    int return_code = compare_arrays(src, len_src, ans, len_ans);

    ck_assert_int_eq(return_code, OK);
}
END_TEST


START_TEST(test_sort_pos_elems)
{
    int src[] = {2, 4 ,6, 2, 1, 9, 3};
    int len_src = 7;

    int ans[] = {1, 2, 2, 3, 4, 6, 9};
    int len_ans = 7;

    mysort(src, len_src, sizeof(int), comp);

    int return_code = compare_arrays(src, len_src, ans, len_ans);

    ck_assert_int_eq(return_code, OK);
}
END_TEST


START_TEST(test_sort_neg_elems)
{
    int src[] = {-2, -3, -1, -3};
    int len_src = 4;

    int ans[] = {-3, -3, -2, -1};
    int len_ans = 4;

    mysort(src, len_src, sizeof(int), comp);

    int return_code = compare_arrays(src, len_src, ans, len_ans);

    ck_assert_int_eq(return_code, OK);
}
END_TEST


START_TEST(test_sort_pos_reverse)
{
    int src[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len_src = 9;

    int ans[] = {1, 2, 3, 4, 5, 6, 7, 8 ,9};
    int len_ans = 9;

    mysort(src, len_src, sizeof(int), comp);

    int return_code = compare_arrays(src, len_src, ans, len_ans);

    ck_assert_int_eq(return_code, OK);
}
END_TEST


START_TEST(test_sort_sorted)
{
    int src[] = {1, 2, 3, 4, 5, 6};
    int len_src = 6;

    int ans[] = {1, 2, 3, 4, 5, 6};
    int len_ans = 6;

    mysort(src, len_src, sizeof(int), comp);

    int return_code = compare_arrays(src, len_src, ans, len_ans);

    ck_assert_int_eq(return_code, OK);
}
END_TEST


START_TEST(test_sort_one_elem)
{
    int src[] = {1};
    int len_src = 1;

    int ans[] = {1};
    int len_ans = 1;

    mysort(src, len_src, sizeof(int), comp);

    int return_code = compare_arrays(src, len_src, ans, len_ans);

    ck_assert_int_eq(return_code, OK);
}
END_TEST


Suite *sort_suite(Suite *s)
{
TCase *tc_pos;

tc_pos = tcase_create("positives");

tcase_add_test(tc_pos, test_sort_equal_elems);
tcase_add_test(tc_pos, test_sort_pos_elems);
tcase_add_test(tc_pos, test_sort_neg_elems);
tcase_add_test(tc_pos, test_sort_pos_reverse);
tcase_add_test(tc_pos, test_sort_sorted);
tcase_add_test(tc_pos, test_sort_one_elem);

suite_add_tcase(s, tc_pos);

return s;
}