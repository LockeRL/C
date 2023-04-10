#ifndef FILE_WRITE_H
#define FILE_WRITE_H

#include <stdio.h>
#include "errors.h"
#include "file_read.h"
#include "array.h"

int file_write(arr *a, const char *file_name);

#endif // FILE_WRITE_H