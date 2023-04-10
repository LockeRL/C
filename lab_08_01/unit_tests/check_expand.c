#include "../inc/check_main.h"
#include "../inc/transform.h"

// Postives

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

    matrix ans = init_matrix();
    if (!alloc_matrix(&ans, 3, 3))
        rc = ERROR;

    ans.mat[0][0] = 1;
    ans.mat[0][1] = 2;
    ans.mat[0][2] = 2;
    ans.mat[1][0] = 3;
    ans.mat[1][1] = 4;
    ans.mat[1][2] = 4;
    ans.mat[2][0] = 2;
    ans.mat[2][1] = 3;
    ans.mat[2][2] = 3;

    if (expand(&a, 3))
        rc = ERROR;

    rc = compare_matrix(&a, &ans);

    ck_assert_int_eq(rc, OK);

    free_a_b(&a, &ans);
}
END_TEST


START_TEST(test_zero)
{
    int rc = OK;
    matrix a = init_matrix();
    if (!alloc_matrix(&a, 2, 2))
        rc = ERROR;

    a.mat[0][0] = 0;
    a.mat[0][1] = 0;
    a.mat[1][0] = 0;
    a.mat[1][1] = 0;

    matrix ans = init_matrix();
    if (!alloc_matrix(&ans, 3, 3))
        rc = ERROR;

    ans.mat[0][0] = 0;
    ans.mat[0][1] = 0;
    ans.mat[0][2] = 0;
    ans.mat[1][0] = 0;
    ans.mat[1][1] = 0;
    ans.mat[1][2] = 0;
    ans.mat[2][0] = 0;
    ans.mat[2][1] = 0;
    ans.mat[2][2] = 0;

    if (expand(&a, 3))
        rc = ERROR;

    rc = compare_matrix(&a, &ans);

    ck_assert_int_eq(rc, OK);

    free_a_b(&a, &ans);
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

    matrix ans = init_matrix();
    if (!alloc_matrix(&ans, 3, 3))
        rc = ERROR;

    ans.mat[0][0] = -1;
    ans.mat[0][1] = -2;
    ans.mat[0][2] = -1;
    ans.mat[1][0] = -3;
    ans.mat[1][1] = -4;
    ans.mat[1][2] = -3;
    ans.mat[2][0] = -2;
    ans.mat[2][1] = -3;
    ans.mat[2][2] = -2;

    if (expand(&a, 3))
        rc = ERROR;

    rc = compare_matrix(&a, &ans);

    ck_assert_int_eq(rc, OK);

    free_a_b(&a, &ans);
}
END_TEST


Suite *expand_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_pos);
    tcase_add_test(tc_pos, test_neg);
    tcase_add_test(tc_pos, test_zero);

    suite_add_tcase(s, tc_pos);

    return s;
}