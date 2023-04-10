#include "../inc/matrix.h"
#include "../inc/input_matrix.h"
#include "../inc/transform.h"
#include "../inc/multiply.h"
#include "../inc/print_matrix.h"

int main()
{
    matrix a = init_matrix();
    matrix b = init_matrix();

    if (input_matrix(&a))
        return INPUT_ERROR;

    if (input_matrix(&b))
    {
        free_matrix(&a);
        return INPUT_ERROR;
    }

    if (scanf("%d %d", &a.power, &b.power) != 2 || a.power < 0 || b.power < 0)
    {
        free_a_b(&a, &b);
        return INPUT_ERROR;
    }

    if (make_square(&a) || make_square(&b))
    {
        free_a_b(&a, &b);
        return MEMORY_ERROR;
    }

    if (expand(a.n > b.n ? &b : &a, a.n > b.n ? a.n : b.n))
    {
        free_a_b(&a, &b);
        return MEMORY_ERROR;
    }

    matrix res = init_matrix();

    if (calc_multiply_result(&a, &b, &res))
    {
        free_a_b(&a, &b);
        return MEMORY_ERROR;
    }

    print_matrix(&res);

    free_a_b(&a, &b);
    free_matrix(&res);

    return EXIT_SUCCESS;
}
