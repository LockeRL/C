#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <stdbool.h>
#include <math.h>
#include "matrix.h"
#include "errors.h"

int make_square(matrix *a);
int expand(matrix *a, int size_dst);

#endif // TRANSFORM_H