#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include "errors.h"

typedef struct
{
    int **mat;
    int n;
    int m;
    int power;
} matrix;

matrix init_matrix(void);
int alloc_matrix(matrix *a, int n, int m);
void free_matrix(matrix *a);
int **get_pi(int **a, int i);
int *get_element(int **a, int i, int j);
void free_a_b(matrix *a, matrix *b);

#endif // MATRIX_H