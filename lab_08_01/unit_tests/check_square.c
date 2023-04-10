#include "../inc/check_main.h"
#include "../inc/transform.h"

// Postives

START_TEST(test_col_del_pos)
{
    int rc = OK;
    matrix a = init_matrix();
    if (!alloc_matrix(&a, 2, 4))
        rc = ERROR;

    a.mat[0][0] = 1;
    a.mat[0][1] = 2;
    a.mat[0][2] = 3;
    a.mat[0][3] = 4;
    a.mat[1][0] = 9;
    a.mat[1][1] = 1;
    a.mat[1][2] = 8;
    a.mat[1][3] = 1;

    matrix ans = init_matrix();
    if (!alloc_matrix(&ans, 2, 2))
        rc = ERROR;

    ans.mat[0][0] = 2;
    ans.mat[0][1] = 4;
    ans.mat[1][0] = 1;
    ans.mat[1][1] = 1;

    if (make_square(&a))
        rc = ERROR;

    rc = compare_matrix(&a, &ans);

    ck_assert_int_eq(rc, OK);

    free_a_b(&a, &ans);
}
END_TEST


START_TEST(test_col_del_neg)
{
    int rc = OK;
    matrix a = init_matrix();
    if (!alloc_matrix(&a, 2, 4))
        rc = ERROR;

    a.mat[0][0] = -1;
    a.mat[0][1] = -2;
    a.mat[0][2] = -3;
    a.mat[0][3] = -4;
    a.mat[1][0] = -9;
    a.mat[1][1] = -1;
    a.mat[1][2] = -8;
    a.mat[1][3] = -1;

    matrix ans = init_matrix();
    if (!alloc_matrix(&ans, 2, 2))
        rc = ERROR;

    ans.mat[0][0] = -3;
    ans.mat[0][1] = -4;
    ans.mat[1][0] = -8;
    ans.mat[1][1] = -1;

    if (make_square(&a))
        rc = ERROR;

    rc = compare_matrix(&a, &ans);

    ck_assert_int_eq(rc, OK);

    free_a_b(&a, &ans);
}
END_TEST


START_TEST(test_col_del_zero)
{
    int rc = OK;
    matrix a = init_matrix();
    if (!alloc_matrix(&a, 2, 4))
        rc = ERROR;

    a.mat[0][0] = 0;
    a.mat[0][1] = 0;
    a.mat[0][2] = 0;
    a.mat[0][3] = 0;
    a.mat[1][0] = 0;
    a.mat[1][1] = 0;
    a.mat[1][2] = 0;
    a.mat[1][3] = 0;

    matrix ans = init_matrix();
    if (!alloc_matrix(&ans, 2, 2))
        rc = ERROR;

    ans.mat[0][0] = 0;
    ans.mat[0][1] = 0;
    ans.mat[1][0] = 0;
    ans.mat[1][1] = 0;

    if (make_square(&a))
        rc = ERROR;

    rc = compare_matrix(&a, &ans);

    ck_assert_int_eq(rc, OK);

    free_a_b(&a, &ans);
}
END_TEST


START_TEST(test_line_del_pos)
{
    int rc = OK;
    matrix a = init_matrix();
    if (!alloc_matrix(&a, 4, 2))
        rc = ERROR;

    a.mat[0][0] = 1;
    a.mat[0][1] = 2;
    a.mat[1][0] = 3;
    a.mat[1][1] = 4;
    a.mat[2][0] = 4;
    a.mat[2][1] = 3;
    a.mat[3][0] = 2;
    a.mat[3][1] = 1;

    matrix ans = init_matrix();
    if (!alloc_matrix(&ans, 2, 2))
        rc = ERROR;

    ans.mat[0][0] = 1;
    ans.mat[0][1] = 2;
    ans.mat[1][0] = 2;
    ans.mat[1][1] = 1;

    if (make_square(&a))
        rc = ERROR;

    rc = compare_matrix(&a, &ans);

    ck_assert_int_eq(rc, OK);

    free_a_b(&a, &ans);
}
END_TEST


START_TEST(test_line_del_neg)
{
    int rc = OK;
    matrix a = init_matrix();
    if (!alloc_matrix(&a, 2, 1))
        rc = ERROR;

    a.mat[0][0] = -2;
    a.mat[1][0] = -4;

    matrix ans = init_matrix();
    if (!alloc_matrix(&ans, 1, 1))
        rc = ERROR;

    ans.mat[0][0] = -4;

    if (make_square(&a))
        rc = ERROR;

    rc = compare_matrix(&a, &ans);

    ck_assert_int_eq(rc, OK);

    free_a_b(&a, &ans);
}
END_TEST

START_TEST(test_line_del_zero)
{
    int rc = OK;
    matrix a = init_matrix();
    if (!alloc_matrix(&a, 4, 2))
        rc = ERROR;

    a.mat[0][0] = 0;
    a.mat[0][1] = 0;
    a.mat[1][0] = 0;
    a.mat[1][1] = 0;
    a.mat[2][0] = 0;
    a.mat[2][1] = 0;
    a.mat[3][0] = 0;
    a.mat[3][1] = 0;

    matrix ans = init_matrix();
    if (!alloc_matrix(&ans, 2, 2))
        rc = ERROR;

    ans.mat[0][0] = 0;
    ans.mat[0][1] = 0;
    ans.mat[1][0] = 0;
    ans.mat[1][1] = 0;

    if (make_square(&a))
        rc = ERROR;

    rc = compare_matrix(&a, &ans);

    ck_assert_int_eq(rc, OK);

    free_a_b(&a, &ans);
}
END_TEST

START_TEST(test_square)
{
    int rc = OK;
    matrix a = init_matrix();
    if (!alloc_matrix(&a, 2, 2))
        rc = ERROR;

    a.mat[0][0] = 1;
    a.mat[0][1] = 2;
    a.mat[1][0] = 3;
    a.mat[1][1] = 4;

    matrix ans = init_matrix();
    if (!alloc_matrix(&ans, 2, 2))
        rc = ERROR;

    ans.mat[0][0] = 1;
    ans.mat[0][1] = 2;
    ans.mat[1][0] = 3;
    ans.mat[1][1] = 4;

    if (make_square(&a))
        rc = ERROR;

    rc = compare_matrix(&a, &ans);

    ck_assert_int_eq(rc, OK);

    free_a_b(&a, &ans);
}
END_TEST


Suite *square_suite(Suite *s)
{
TCase *tc_pos;

tc_pos = tcase_create("positives");

tcase_add_test(tc_pos, test_col_del_pos);
tcase_add_test(tc_pos, test_col_del_neg);
tcase_add_test(tc_pos, test_col_del_zero);
tcase_add_test(tc_pos, test_line_del_pos);
tcase_add_test(tc_pos, test_line_del_neg);
tcase_add_test(tc_pos, test_line_del_zero);
tcase_add_test(tc_pos, test_square);

suite_add_tcase(s, tc_pos);

return s;
}