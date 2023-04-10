#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdbool.h>

void mysort(void *pb, size_t n, size_t size, int (*comp)(const void *, const void *));
int comp(const void *a, const void *b);

#endif // SORT_H