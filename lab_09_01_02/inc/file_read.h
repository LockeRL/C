#ifndef FILE_READ_H
#define FILE_READ_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "item.h"
#include "string_work.h"
#include "errors.h"

int copy_array_from_file(item_arr *a, int max_size, const char *file_name);

#endif // FILE_READ_H
