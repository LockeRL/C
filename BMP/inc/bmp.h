#ifndef BMP_H
#define BMP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <inttypes.h>
#include <math.h>


#define AMOUNT_ARGS 4
#define OK 0
#define ERR_NO_ARGS -1
#define ERR_OPEN_FILE -2
#define ERR_BMP_FILE -3
#define ERR_ALLOC -4
#define ERR_CORE -5

#define MAX_COLOR 255
#define MIN_COLOR 0

#define GAUSS_RAD 20
#define GAUSS_SIGMA 1.94
#define PI acos(-1.0)

#define LAPLAS_LIMIT 3

#define MEDIAN_RAD 5


#pragma pack(push, 1)
typedef struct{
    uint16_t type;
    uint32_t bfSize;
    uint32_t bfReserved;
    uint32_t bfOffBits;

    uint32_t biSize;
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} bmp_header;
#pragma pack(pop)

typedef struct
{
    uint8_t b;
    uint8_t g;
    uint8_t r;
} pixel;

typedef struct
{
    bmp_header header;
    pixel **bitmap;
} bmp_image;

typedef struct
{
    float **core;
    int n;
    int m;
} core;

typedef struct
{
    int i;
    int j;
} pixel_pos;

int process_img(const char *file_name_src, const char *file_name_dst, int command, float *core_arr, int n, int m);

#endif
