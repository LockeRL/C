#include "../inc/multiply.h"
#include "../inc/check_main.h"

START_TEST(test_zero_power_a)
{
    int rc = OK;
    matrix a = init_matrix();
    if (!alloc_matrix(&a, 2, 2))
        rc = ERROR;

    a.mat[0][0] = 1;
    a.mat[0][1] = 2;
    a.mat[1][0] = 3;
    a.mat[1][1] = 4;

    a.power = 0;

    rc = OK;
    matrix b = init_matrix();
    if (!alloc_matrix(&b, 2, 2))
        rc = ERROR;

    b.mat[0][0] = 4;
    b.mat[0][1] = 3;
    b.mat[1][0] = 2;
    b.mat[1][1] = 1;

    b.power = 1;

    matrix ans = init_matrix();
    if (!alloc_matrix(&ans, 2, 2))
        rc = ERROR;

    ans.mat[0][0] = 4;
    ans.mat[0][1] = 3;
    ans.mat[1][0] = 2;
    ans.mat[1][1] = 1;

    matrix res = init_matrix();

    if (calc_multiply_result(&a, &b, &res))
        rc = ERROR;

    rc = compare_matrix(&res, &ans);

    ck_assert_int_eq(rc, OK);

    free_a_b(&a, &b);
    free_matrix(&ans);
    free_matrix(&res);
}
END_TEST


START_TEST(test_zero_power_b)
{
    int rc = OK;
    matrix a = init_matrix();
    if (!alloc_matrix(&a, 2, 2))
        rc = ERROR;

    a.mat[0][0] = 1;
    a.mat[0][1] = 2;
    a.mat[1][0] = 3;
    a.mat[1][1] = 4;

    a.power = 1;

    rc = OK;
    matrix b = init_matrix();
    if (!alloc_matrix(&b, 2, 2))
        rc = ERROR;

    b.mat[0][0] = 4;
    b.mat[0][1] = 3;
    b.mat[1][0] = 2;
    b.mat[1][1] = 1;

    b.power = 0;

    matrix ans = init_matrix();
    if (!alloc_matrix(&ans, 2, 2))
        rc = ERROR;

    ans.mat[0][0] = 1;
    ans.mat[0][1] = 2;
    ans.mat[1][0] = 3;
    ans.mat[1][1] = 4;

    matrix res = init_matrix();

    if (calc_multiply_result(&a, &b, &res))
        rc = ERROR;

    rc = compare_matrix(&res, &ans);

    ck_assert_int_eq(rc, OK);

    free_a_b(&a, &b);
    free_matrix(&ans);
    free_matrix(&res);
}
END_TEST


START_TEST(test_zero_power_both)
{
    int rc = OK;
    matrix a = init_matrix();
    if (!alloc_matrix(&a, 2, 2))
        rc = ERROR;

    a.mat[0][0] = 1;
    a.mat[0][1] = 2;
    a.mat[1][0] = 3;
    a.mat[1][1] = 4;

    a.power = 0;

    rc = OK;
    matrix b = init_matrix();
    if (!alloc_matrix(&b, 2, 2))
        rc = ERROR;

    b.mat[0][0] = 4;
    b.mat[0][1] = 3;
    b.mat[1][0] = 2;
    b.mat[1][1] = 1;

    b.power = 0;

    matrix ans = init_matrix();
    if (!alloc_matrix(&ans, 2, 2))
        rc = ERROR;

    ans.mat[0][0] = 1;
    ans.mat[0][1] = 0;
    ans.mat[1][0] = 0;
    ans.mat[1][1] = 1;

    matrix res = init_matrix();

    if (calc_multiply_result(&a, &b, &res))
        rc = ERROR;

    rc = compare_matrix(&res, &ans);

    ck_assert_int_eq(rc, OK);

    free_a_b(&a, &b);
    free_matrix(&ans);
    free_matrix(&res);
}
END_TEST


START_TEST(test_neg)
{
    int rc = OK;
    matrix a = init_matrix();
    if (!alloc_matrix(&a, 2, 2))
        rc = ERROR;

    a.mat[0][0] = -1;
    a.mat[0][1] = -2;
    a.mat[1][0] = -3;
    a.mat[1][1] = -4;

    a.power = 2;

    rc = OK;
    matrix b = init_matrix();
    if (!alloc_matrix(&b, 2, 2))
        rc = ERROR;

    b.mat[0][0] = -4;
    b.mat[0][1] = -3;
    b.mat[1][0] = -2;
    b.mat[1][1] = -1;

    b.power = 2;

    matrix ans = init_matrix();
    if (!alloc_matrix(&ans, 2, 2))
        rc = ERROR;

    ans.mat[0][0] = 254;
    ans.mat[0][1] = 175;
    ans.mat[1][0] = 550;
    ans.mat[1][1] = 379;

    matrix res = init_matrix();

    if (calc_multiply_result(&a, &b, &res))
        rc = ERROR;

    rc = compare_matrix(&res, &ans);

    ck_assert_int_eq(rc, OK);

    free_a_b(&a, &b);
    free_matrix(&ans);
    free_matrix(&res);
}
END_TEST


START_TEST(test_pos)
{
    int rc = OK;
    matrix a = init_matrix();
    if (!alloc_matrix(&a, 2, 2))
        rc = ERROR;

    a.mat[0][0] = 1;
    a.mat[0][1] = 2;
    a.mat[1][0] = 3;
    a.mat[1][1] = 4;

    a.power = 2;

    rc = OK;
    matrix b = init_matrix();
    if (!alloc_matrix(&b, 2, 2))
        rc = ERROR;

    b.mat[0][0] = 4;
    b.mat[0][1] = 3;
    b.mat[1][0] = 2;
    b.mat[1][1] = 1;

    b.power = 2;

    matrix ans = init_matrix();
    if (!alloc_matrix(&ans, 2, 2))
        rc = ERROR;

    ans.mat[0][0] = 254;
    ans.mat[0][1] = 175;
    ans.mat[1][0] = 550;
    ans.mat[1][1] = 379;

    matrix res = init_matrix();

    if (calc_multiply_result(&a, &b, &res))
        rc = ERROR;

    rc = compare_matrix(&res, &ans);

    ck_assert_int_eq(rc, OK);

    free_a_b(&a, &b);
    free_matrix(&ans);
    free_matrix(&res);
}
END_TEST


Suite *multiply_suite(Suite *s)
{
TCase *tc_pos;

tc_pos = tcase_create("positives");

tcase_add_test(tc_pos, test_zero_power_a);
tcase_add_test(tc_pos, test_zero_power_b);
tcase_add_test(tc_pos, test_zero_power_both);
tcase_add_test(tc_pos, test_pos);
tcase_add_test(tc_pos, test_neg);

suite_add_tcase(s, tc_pos);

return s;
}