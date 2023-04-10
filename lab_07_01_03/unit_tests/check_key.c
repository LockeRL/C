#include "../inc/key.h"
#include "../inc/check_main.h"

// Postives

START_TEST(test_filter_pos_nums)
{
        int pb_src[] = {1, 4, 2, 4, 3, 8, 2, 5};
        int *pe_src = pb_src + 7;

        int *pb_dst = NULL;
        int *pe_dst = NULL;

        key(pb_src, pe_src, &pb_dst, &pe_dst);
        int dst_len = pe_dst - pb_dst;

        int ans[] = {1, 4, 2, 4, 3, 8, 2, 5};
        int ans_len = 7;

        int return_code = compare_arrays(pb_dst, dst_len, ans, ans_len);

        ck_assert_int_eq(return_code, OK);

        free(pb_dst);
}
END_TEST


START_TEST(test_filter_neg_nums)
{
    int pb_src[] = {-1, -4, -2, -4, -3, -8, -2, -5};
    int *pe_src = pb_src + 7;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    key(pb_src, pe_src, &pb_dst, &pe_dst);
    int dst_len = pe_dst - pb_dst;

    int ans[] = {-1, -4, -2, -4, -3, -8, -2};
    int ans_len = 6;

    int return_code = compare_arrays(pb_dst, dst_len, ans, ans_len);

    ck_assert_int_eq(return_code, OK);

    free(pb_dst);
}
END_TEST


START_TEST(test_filter_one_neg)
{
    int pb_src[] = {1, 4, 2, -4, 3, 8, 2, 5};
    int *pe_src = pb_src + 7;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    key(pb_src, pe_src, &pb_dst, &pe_dst);
    int dst_len = pe_dst - pb_dst;

    int ans[] = {1, 4, 2};
    int ans_len = 3;

    int return_code = compare_arrays(pb_dst, dst_len, ans, ans_len);

    ck_assert_int_eq(return_code, OK);

    free(pb_dst);
}
END_TEST


START_TEST(test_filter_two_neg)
{
    int pb_src[] = {1, 4, 2, -4, 3, -8, 2, 5};
    int *pe_src = pb_src + 7;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    key(pb_src, pe_src, &pb_dst, &pe_dst);
    int dst_len = pe_dst - pb_dst;

    int ans[] = {1, 4, 2, -4, 3};
    int ans_len = 5;

    int return_code = compare_arrays(pb_dst, dst_len, ans, ans_len);

    ck_assert_int_eq(return_code, OK);

    free(pb_dst);
}
END_TEST


START_TEST(test_filter_one_pos_elem)
{
    int pb_src[] = {1};
    int *pe_src = pb_src + 1;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    key(pb_src, pe_src, &pb_dst, &pe_dst);
    int dst_len = pe_dst - pb_dst;

    int ans[] = {1};
    int ans_len = 1;

    int return_code = compare_arrays(pb_dst, dst_len, ans, ans_len);

    ck_assert_int_eq(return_code, OK);

    free(pb_dst);
}
END_TEST


// Negative

START_TEST(test_filter_empty_arr)
{
    int pb_src[] = {1};
    int *pe_src = pb_src;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int return_code = key(pb_src, pe_src, &pb_dst, &pe_dst);

    ck_assert_int_eq(return_code, ERROR);

    free(pb_dst);
}
END_TEST


START_TEST(test_filter_one_neg_first)
{
    int pb_src[] = {-2};
    int *pe_src = pb_src + 1;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int return_code = key(pb_src, pe_src, &pb_dst, &pe_dst);

    ck_assert_int_eq(return_code, ERROR);

    free(pb_dst);
}
END_TEST

START_TEST(test_filter_NULL_src)
{
    int *pb_src = NULL;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int return_code = key(pb_src, pb_src, &pb_dst, &pe_dst);

    ck_assert_int_eq(return_code, ERROR);

    free(pb_dst);
}
END_TEST


Suite *key_suite(Suite *s)
{
TCase *tc_pos, *tc_neg;

tc_pos = tcase_create("positives");

tcase_add_test(tc_pos, test_filter_pos_nums);
tcase_add_test(tc_pos, test_filter_neg_nums);
tcase_add_test(tc_pos, test_filter_one_neg);
tcase_add_test(tc_pos, test_filter_two_neg);
tcase_add_test(tc_pos, test_filter_one_pos_elem);

suite_add_tcase(s, tc_pos);

tc_neg = tcase_create("negatives");

tcase_add_test(tc_neg, test_filter_empty_arr);
tcase_add_test(tc_neg, test_filter_one_neg_first);
tcase_add_test(tc_neg, test_filter_NULL_src);

suite_add_tcase(s, tc_neg);

return s;
}