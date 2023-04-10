#include "../inc/check_main.h"
#include "../inc/sort.h"

// Postives

START_TEST(test_two_swap)
{
    int rc = OK;
    item_arr a = init_arr();
    a.arr = calloc(2, sizeof(item));
    a.n = 2;

    a.arr[0].name = strdup("abc");
    a.arr[0].weight = 12;
    a.arr[0].volume = 2;
    a.arr[1].name = strdup("abc");
    a.arr[1].weight = 10;
    a.arr[1].volume = 2;

    item_arr ans = init_arr();
    ans.arr = calloc(2, sizeof(item));
    ans.n = 2;


    ans.arr[0].name = strdup("abc");
    ans.arr[0].weight = 10;
    ans.arr[0].volume = 2;
    ans.arr[1].name = strdup("abc");
    ans.arr[1].weight = 12;
    ans.arr[1].volume = 2;


    double *dens_arr = create_dens_arr(&a);
    sort_by_density(&a, dens_arr);
    free(dens_arr);

    rc = compare_item_arr(&a, &ans);

    ck_assert_int_eq(rc, OK);

    free_item_arr(&a);
    free_item_arr(&ans);
}
END_TEST


START_TEST(test_normal_order)
{
    int rc = OK;
    item_arr a = init_arr();
    a.arr = calloc(2, sizeof(item));
    a.n = 2;

    a.arr[0].name = strdup("abc");
    a.arr[0].weight = 12;
    a.arr[0].volume = 2;
    a.arr[1].name = strdup("abc");
    a.arr[1].weight = 20;
    a.arr[1].volume = 2;

    item_arr ans = init_arr();
    ans.arr = calloc(2, sizeof(item));
    ans.n = 2;

    ans.arr[0].name = strdup("abc");
    ans.arr[0].weight = 12;
    ans.arr[0].volume = 2;
    ans.arr[1].name = strdup("abc");
    ans.arr[1].weight = 20;
    ans.arr[1].volume = 2;


    double *dens_arr = create_dens_arr(&a);
    sort_by_density(&a, dens_arr);
    free(dens_arr);

    rc = compare_item_arr(&a, &ans);

    ck_assert_int_eq(rc, OK);

    free_item_arr(&a);
    free_item_arr(&ans);
}
END_TEST


START_TEST(test_one)
{
    int rc = OK;
    item_arr a = init_arr();
    a.arr = calloc(1, sizeof(item));
    a.n = 1;

    a.arr[0].name = strdup("abc");
    a.arr[0].weight = 12;
    a.arr[0].volume = 2;

    item_arr ans = init_arr();
    ans.arr = calloc(1, sizeof(item));
    ans.n = 1;

    ans.arr[0].name = strdup("abc");
    ans.arr[0].weight = 12;
    ans.arr[0].volume = 2;


    double *dens_arr = create_dens_arr(&a);
    sort_by_density(&a, dens_arr);
    free(dens_arr);

    rc = compare_item_arr(&a, &ans);

    ck_assert_int_eq(rc, OK);

    free_item_arr(&a);
    free_item_arr(&ans);
}
END_TEST

START_TEST(test_invert)
{
    int rc = OK;
    item_arr a = init_arr();
    a.arr = calloc(3, sizeof(item));
    a.n = 3;

    a.arr[0].name = strdup("c");
    a.arr[0].weight = 20;
    a.arr[0].volume = 2;
    a.arr[1].name = strdup("b");
    a.arr[1].weight = 15;
    a.arr[1].volume = 2;
    a.arr[2].name = strdup("a");
    a.arr[2].weight = 10;
    a.arr[2].volume = 2;

    item_arr ans = init_arr();
    ans.arr = calloc(3, sizeof(item));
    ans.n = 3;

    ans.arr[0].name = strdup("a");
    ans.arr[0].weight = 10;
    ans.arr[0].volume = 2;
    ans.arr[1].name = strdup("b");
    ans.arr[1].weight = 15;
    ans.arr[1].volume = 2;
    ans.arr[2].name = strdup("c");
    ans.arr[2].weight = 20;
    ans.arr[2].volume = 2;


    double *dens_arr = create_dens_arr(&a);
    sort_by_density(&a, dens_arr);
    free(dens_arr);

    rc = compare_item_arr(&a, &ans);

    ck_assert_int_eq(rc, OK);

    free_item_arr(&a);
    free_item_arr(&ans);
}
END_TEST


Suite *sort_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_two_swap);
    tcase_add_test(tc_pos, test_normal_order);
    tcase_add_test(tc_pos, test_one);
    tcase_add_test(tc_pos, test_invert);

    suite_add_tcase(s, tc_pos);

    return s;
}