#ifndef FILE_READ_H
#define FILE_READ_H

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "errors.h"
#include "array.h"

int file_read(arr *a, const char *file_name);
int open_file(FILE **f, const char *file_name, const char *mode);

#endif //FILE_READ_H