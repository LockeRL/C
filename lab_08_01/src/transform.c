#include "../inc/transform.h"

/*
 * @return f = true - line, else column
 */
int find_max(matrix *a, bool f)
{
    int max = a->mat[0][0];
    int max_i = 0;
    int max_j = 0;

    for (int i = 0; i < a->n; i++)
        for (int j = 0; j < a->m; j++)
            if (a->mat[i][j] > max)
            {
                max = a->mat[i][j];
                max_i = i;
                max_j = j;
            }

    return f ? max_i : max_j;
}

void delete_line(matrix *a, int pos)
{
    free(*get_pi(a->mat, pos));
    for (int i = pos; i < a->n - 1; i++)
        *get_pi(a->mat, i) = *get_pi(a->mat, i + 1);

    a->n--;
}

int delete_lines(matrix *a, int count)
{
    for (int i = 0; i < count; i++)
        delete_line(a, find_max(a, true));

    int rc = OK;
    int **tmp = realloc(a->mat, a->n * sizeof(int*));
    if (!tmp)
    {
        free_matrix(a);
        rc = MEMORY_ERROR;
    }
    a->mat = tmp;

    return rc;
}

void delete_column(matrix *a, int pos)
{
    for (int j = pos; j < a->m - 1; j++)
        for (int i = 0; i < a->n; i++)
            *get_element(a->mat, i, j) = *get_element(a->mat, i, j + 1);

    a->m--;
}

int delete_columns(matrix *a, int count)
{
    for (int i = 0; i < count; i++)
        delete_column(a, find_max(a, false));

    int *tmp;
    int rc = OK;
    for (int i = 0; rc == OK && i < a->n; i++)
    {
        tmp = realloc(*get_pi(a->mat, i), a->m * sizeof(int));
        if (!tmp)
        {
            free_matrix(a);
            rc = MEMORY_ERROR;
        }
        *get_pi(a->mat, i) = tmp;
    }

    return rc;
}

int make_square(matrix *a)
{
    int rc = OK;
    if (a->n > a->m)
        rc = delete_lines(a, a->n - a->m);
    else if (a->m > a->n)
        rc = delete_columns(a, a->m - a->n);
    return rc;
}

int max_in_line(const int *a, int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

int sum_in_column(matrix *a, int column)
{
    int sum = 0;
    for (int i = 0; i < a->n; i++)
        sum += a->mat[i][column];
    return sum;
}

int *create_line(matrix *a)
{
    int *line = calloc(a->m, sizeof(int));
    if (!line)
        return NULL;
    for (int i = 0; i < a->m; i++)
        line[i] = (int)floor(sum_in_column(a, i) * 1.0 / a->n);

    return line;
}

int expand_lines(matrix *a, int lines_dst)
{
    int **tmp;
    tmp = realloc(a->mat, lines_dst * sizeof(int*));
    if (!tmp)
    {
        free_matrix(a);
        return MEMORY_ERROR;
    }
    a->mat = tmp;

    int rc = OK;
    for (; rc == OK && a->n < lines_dst; a->n++)
        if (!(*get_pi(a->mat, a->n) = create_line(a)))
        {
            free_matrix(a);
            rc = MEMORY_ERROR;
        }

    return rc;
}

int expand_columns(matrix *a, int columns_dst)
{
    int *tmp;
    int rc = OK;
    for (int i = 0; rc == OK && i < a->n; i++)
    {
        tmp = realloc(*get_pi(a->mat, i), columns_dst * sizeof(int));
        if (!tmp)
        {
            free_matrix(a);
            rc = MEMORY_ERROR;
        }
        *get_pi(a->mat, i) = tmp;
    }

    for (; rc == OK && a->m < columns_dst; a->m++)
        for (int i = 0; i < a->n; i++)
            *get_element(a->mat, i, a->m) = max_in_line(*get_pi(a->mat, i), a->m);

    return rc;
}

int expand(matrix *a, int size_dst)
{
    if (expand_lines(a, size_dst))
        return MEMORY_ERROR;
    if (expand_columns(a, size_dst))
        return MEMORY_ERROR;
    return OK;
}

/*
2 3
4 7 1
3 2 7
5 3
0 2 9
1 2 2
3 3 3
8 8 2
1 8 3
2 3
 */