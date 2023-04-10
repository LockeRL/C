#include "../inc/bmp.h"

pixel **alloc_bitmap(int32_t n, int32_t m);

bmp_image create_out_bmp(bmp_header *head)
{
    bmp_image a;
    a.header = *head;
    a.bitmap = alloc_bitmap(head->biHeight, head->biWidth);
    return a;
}

int read_bmp(bmp_image *image, const char *filename)
{
    int rc = OK;
    FILE* f = fopen(filename, "rb");
    if (f == NULL)
        rc = ERR_OPEN_FILE;

    if (rc == OK)
        fread(&image->header, sizeof(bmp_header), 1, f);

    if (rc == OK && image->header.type != 0x4D42 && image->header.biBitCount != 24)
        rc = ERR_BMP_FILE;

    if (rc == OK)
    {
        fseek(f, image->header.bfOffBits, SEEK_SET);

        image->bitmap = alloc_bitmap(image->header.biHeight, image->header.biWidth);
    }

    if (rc && image->bitmap == NULL)
        rc = ERR_ALLOC;

    for(int32_t i = 0; rc == OK && i < image->header.biHeight; i++)
        for (int32_t j = 0; j < image->header.biWidth; j++)
            fread(&image->bitmap[i][j], sizeof(pixel), 1, f);

    fclose(f);

	return rc;
}

pixel **alloc_bitmap(int32_t n, int32_t m)
{
    pixel **mat = malloc(n * sizeof(pixel*) + n * m * sizeof(pixel));

    if (!mat)
        return NULL;

    for (int32_t i = 0; i < n; i++)
        mat[i] = (pixel*)((char*)mat + n * sizeof(pixel*) + i * m * sizeof(pixel));

    return mat;
}

void free_bmp(bmp_image *a)
{
    free(a->bitmap);
    a->bitmap = NULL;
}

int write_bmp(const char *filename, const bmp_image *image)
{
    FILE* f = fopen(filename, "wb");
    if (f == NULL)
        return ERR_OPEN_FILE;

    fwrite(&(image->header), sizeof(bmp_header), 1, f);

    fseek(f, image->header.bfOffBits, SEEK_SET);
    for(int32_t i = 0; i < image->header.biHeight; i++)
        for (int32_t j = 0; j < image->header.biWidth; j++)
            fwrite(&(image->bitmap[i][j]), sizeof(pixel), 1, f);

    fclose(f);

    return OK;
}

pixel make_grey(const pixel *a)
{
    float kr = 0.299f;
    float kb = 0.114f;
    float g = kr * (float)a->r + (1.0f - kr - kb) * (float)a->g + kb * (float)a->b;
    pixel dst;

    dst.r = (uint8_t)g;
    dst.b = (uint8_t)g;
    dst.g = (uint8_t)g;

    return dst;
}

int greyscale(pixel **dst, const bmp_image *src)
{
    for(int32_t i = 0; i < src->header.biHeight; i++)
        for (int32_t j = 0; j < src->header.biWidth; j++)
            dst[i][j] = make_grey(&src->bitmap[i][j]);

    return OK;
}

uint8_t get_red(const pixel *a)
{
    return a->r;
}

uint8_t get_blue(const pixel *a)
{
    return a->b;
}

uint8_t get_green(const pixel *a)
{
    return a->g;
}

uint8_t align_color(double a)
{
    if (a > MAX_COLOR)
        return MAX_COLOR;
    if (a < MIN_COLOR)
        return MIN_COLOR;
    return (uint8_t)a;
}

pixel mult_pixel_with_core(const bmp_image *src, const core *core, const pixel_pos *pos, uint8_t(*align)(double a))
{
    double sum_r = 0, sum_b = 0, sum_g = 0;
    int start_i = pos->i - core->n / 2;
    int start_j = pos->j - core->m / 2;

    int cur_i, cur_j;
    for (int i = 0; i < core->n; i++)
    {
        cur_i = start_i + i;

        if (cur_i < 0)
            cur_i = 0;
        if (cur_i >= src->header.biHeight)
            cur_i = src->header.biHeight - 1;

        for (int j = 0; j < core->m; j++)
        {
            cur_j = start_j + j;

            if (cur_j < 0)
                cur_j = 0;
            if (cur_j >= src->header.biWidth)
                cur_j = src->header.biWidth - 1;

            sum_r += core->core[i][j] * (float)get_red(&src->bitmap[cur_i][cur_j]);
            sum_b += core->core[i][j] * (float)get_blue(&src->bitmap[cur_i][cur_j]);
            sum_g += core->core[i][j] * (float)get_green(&src->bitmap[cur_i][cur_j]);
        }
    }
    pixel a;
    a.r = align(sum_r);
    a.g = align(sum_g);
    a.b = align(sum_b);
    return a;
}

void free_core(core *a)
{
    free(a->core);
    a->core = NULL;
    a->n = 0;
    a->m = 0;
}

float **alloc_core(int n, int m)
{
    float **mat = malloc(n * sizeof(float*) + n * m * sizeof(float));

    if (!mat)
        return NULL;

    for (int i = 0; i < n; i++)
        mat[i] = (float*)((char*)mat + n * sizeof(float*) + i * m * sizeof(float));

    return mat;
}

int create_core(core *a, int n, int m, const float *src)
{
    a->n = n;
    a->m = m;

    a->core = alloc_core(n, m);
    if (a->core == NULL)
        return ERR_ALLOC;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a->core[i][j] = src[i * m + j];

    return OK;
}

uint8_t quadratic_mean(uint8_t a, uint8_t b)
{
    return (uint8_t)(sqrt(pow((double)a, 2.0) + pow((double)b, 2.0)));
}

pixel sobel_pixel(pixel a, pixel b)
{
    pixel dst;
    dst.r = quadratic_mean(a.r, b.r);
    dst.b = quadratic_mean(a.b, b.b);
    dst.g = quadratic_mean(a.g, b.g);
    return dst;
}

int sobel(pixel **dst, const bmp_image *src)
{
    float gx_arr[]  = { -1, 0, 1, -2, 0, 2, -1, 0, 1};
    float gy_arr[]  = { -1, -2, -1, 0, 0, 0, 1, 2, 1};
    core gx, gy;

    if (create_core(&gx, 3, 3, gx_arr))
        return ERR_CORE;

    if (create_core(&gy, 3, 3, gy_arr))
    {
        free_core(&gx);
        return ERR_CORE;
    }

    pixel_pos pos;
    for(int32_t i = 0; i < src->header.biHeight; i++)
    {
        pos.i = i;
        for (int32_t j = 0; j < src->header.biWidth; j++)
        {
            pos.j = j;
            dst[i][j] = sobel_pixel(mult_pixel_with_core(src, &gx, &pos, align_color), mult_pixel_with_core(src, &gy, &pos, align_color));
        }
    }

    free_core(&gx);
    free_core(&gy);

    return OK;
}

int laplas(pixel **dst, const bmp_image *src)
{
    float laplas_arr[] = {0, 1, 0, 1 ,-4, 1, 0, 1 ,0};
    core laplas;

    if (create_core(&laplas, 3, 3, laplas_arr))
        return ERR_CORE;

    pixel_pos pos;
    for(int32_t i = 0; i < src->header.biHeight; i++)
    {
        pos.i = i;
        for (int32_t j = 0; j < src->header.biWidth; j++)
        {
            pos.j = j;
            dst[i][j] = mult_pixel_with_core(src, &laplas, &pos, align_color);
        }
    }

    free_core(&laplas);

    return OK;
}

float gaussian_distr(double x, double y)
{
    double sigma_sqr = GAUSS_SIGMA * GAUSS_SIGMA;
    return (float)(exp(-(x * x + y * y) / 2 / sigma_sqr) / 2 / PI / sigma_sqr);
}

void fill_gauss_arr(float *a)
{
    float sum = 0;
    for (int i = 0; i < GAUSS_RAD; i++)
        for (int j = 0; j < GAUSS_RAD; j++)
        {
            a[i * GAUSS_RAD + j] = gaussian_distr((float)i - (float)GAUSS_RAD / 2, (float)j - (float)GAUSS_RAD / 2);
            sum += a[i * GAUSS_RAD + j];
        }

    for (int i = 0; i < GAUSS_RAD * GAUSS_RAD; i++)
        a[i] /= sum;
}

int gauss(pixel **dst, const bmp_image *src)
{
    float gauss_arr[GAUSS_RAD * GAUSS_RAD];
    fill_gauss_arr(gauss_arr);
    core gauss;

    if (create_core(&gauss, GAUSS_RAD, GAUSS_RAD, gauss_arr))
        return ERR_CORE;

    pixel_pos pos;
    for(int32_t i = 0; i < src->header.biHeight; i++)
    {
        pos.i = i;
        for (int32_t j = 0; j < src->header.biWidth; j++)
        {
            pos.j = j;
            dst[i][j] = mult_pixel_with_core(src, &gauss, &pos, align_color);
        }
    }

    free_core(&gauss);

    return OK;
}

void copy_bitmap(pixel **dst, pixel **src, int32_t n, int32_t m)
{
    for (int32_t i = 0; i < n; i++)
        for (int32_t j = 0; j < m; j++)
            dst[i][j] = src[i][j];
}

uint8_t align_edge(double a)
{
    if (a >= LAPLAS_LIMIT)
        return MAX_COLOR;
    return MIN_COLOR;
}

int laplas_limit(pixel **dst, const bmp_image *src)
{
    float laplas_arr[] = {0, 1, 0, 1 ,-4, 1, 0, 1 ,0};
    core laplas;

    if (create_core(&laplas, 3, 3, laplas_arr))
        return ERR_CORE;

    pixel_pos pos;
    for(int32_t i = 0; i < src->header.biHeight; i++)
    {
        pos.i = i;
        for (int32_t j = 0; j < src->header.biWidth; j++)
        {
            pos.j = j;
            dst[i][j] = mult_pixel_with_core(src, &laplas, &pos, align_edge);
        }
    }

    free_core(&laplas);

    return OK;
}

int edge(pixel **dst, bmp_image *src)
{
    int rc = greyscale(dst, src);

    copy_bitmap(src->bitmap, dst, src->header.biHeight, src->header.biWidth);

    rc = rc == OK ? gauss(dst, src) : rc;

    copy_bitmap(src->bitmap, dst, src->header.biHeight, src->header.biWidth);

    rc = rc == OK ? laplas_limit(dst, src) : rc;

    return rc;
}

int user_core(pixel **dst, const bmp_image *src, core *core)
{
    pixel_pos pos;
    for(int32_t i = 0; i < src->header.biHeight; i++)
    {
        pos.i = i;
        for (int32_t j = 0; j < src->header.biWidth; j++)
        {
            pos.j = j;
            dst[i][j] = mult_pixel_with_core(src, core, &pos, align_color);
        }
    }

    return OK;
}

int comp_red(const void *a, const void *b)
{
    pixel pix_a = *(pixel*)a;
    pixel pix_b = *(pixel*)b;

    return pix_a.r - pix_b.r;
}

int comp_blue(const void *a, const void *b)
{
    pixel pix_a = *(pixel*)a;
    pixel pix_b = *(pixel*)b;

    return pix_a.b - pix_b.b;
}

int comp_green(const void *a, const void *b)
{
    pixel pix_a = *(pixel*)a;
    pixel pix_b = *(pixel*)b;

    return pix_a.g - pix_b.g;
}

pixel median_pixel(const bmp_image *src, const pixel_pos *pos)
{
    int start_i = pos->i - MEDIAN_RAD / 2;
    int start_j = pos->j - MEDIAN_RAD / 2;

    int cur_i, cur_j;

    pixel arr[MEDIAN_RAD * MEDIAN_RAD];
    for (int i = 0; i < MEDIAN_RAD; i++)
    {
        cur_i = start_i + i;

        if (cur_i < 0)
            cur_i = 0;
        if (cur_i >= src->header.biHeight)
            cur_i = src->header.biHeight - 1;

        for (int j = 0; j < MEDIAN_RAD; j++)
        {
            cur_j = start_j + j;

            if (cur_j < 0)
                cur_j = 0;
            if (cur_j >= src->header.biWidth)
                cur_j = src->header.biWidth - 1;

            arr[i * MEDIAN_RAD + j] = src->bitmap[cur_i][cur_j];
        }
    }

    pixel a;
    qsort(arr, MEDIAN_RAD * MEDIAN_RAD, sizeof(pixel), comp_red);
    a.r = get_red(&arr[MEDIAN_RAD * MEDIAN_RAD / 2]);

    qsort(arr, MEDIAN_RAD * MEDIAN_RAD, sizeof(pixel), comp_blue);
    a.b = get_blue(&arr[MEDIAN_RAD * MEDIAN_RAD / 2]);

    qsort(arr, MEDIAN_RAD * MEDIAN_RAD, sizeof(pixel), comp_green);
    a.g = get_green(&arr[MEDIAN_RAD * MEDIAN_RAD / 2]);

    return a;
}

int median(pixel **dst, const bmp_image *src)
{
    pixel_pos pos;
    for(int32_t i = 0; i < src->header.biHeight; i++)
    {
        pos.i = i;
        for (int32_t j = 0; j < src->header.biWidth; j++)
        {
            pos.j = j;
            dst[i][j] = median_pixel(src, &pos);
        }
    }

    return OK;
}

/*
1 - grey
2 - sobel
3 - laplas
4 - gauss
5 - border
6 - user_core
7 - median
 */
int process_img(const char *file_name_src, const char *file_name_dst, int command, float *core_arr, int n, int m)
{
    bmp_image image_src;
    printf("enter\n");
    printf("file_path: %s\n", file_name_src);
    int rc = read_bmp(&image_src, file_name_src);
    printf("read success\n");

    if (rc != OK)
        return rc;

    bmp_image image_dst = create_out_bmp(&image_src.header);
    if (image_dst.bitmap == NULL)
    {
        free_bmp(&image_src);
        return ERR_ALLOC;
    }

    if (command == 1)
        rc = greyscale(image_dst.bitmap, &image_src);
    else if (command == 2)
        rc = sobel(image_dst.bitmap, &image_src);
    else if (command == 3)
        rc = laplas(image_dst.bitmap, &image_src);
    else if (command == 4)
        rc = gauss(image_dst.bitmap, &image_src);
    else if (command == 5)
        rc = edge(image_dst.bitmap, &image_src);
    else if (command == 6)
    {
        core user;
        rc = create_core(&user, n, m, core_arr);
        rc = rc == OK ? user_core(image_dst.bitmap, &image_src, &user) : rc;
        if (rc == OK)
            free_core(&user);
    }
    else if (command == 7)
        rc = median(image_dst.bitmap, &image_src);

    if (rc == OK)
        rc = write_bmp(file_name_dst, &image_dst);

    printf("write_success\n");

    free_bmp(&image_src);
    free_bmp(&image_dst);
    return rc;
}