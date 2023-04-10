#include "../inc/my_snprintf.h"


void long_to_str(char *buf, long num)
{
    int i = 0;

    if (num == 0)
        buf[i++] = '0';

    for (; num; i++)
    {
        buf[i] = '0' + labs(num % 10);
        num /= 10;
    }
    buf[i] = '\0';
}


void int_to_str(char *buf, int num)
{
    int i = 0;

    if (num == 0)
        buf[i++] = '0';

    for (; num; i++)
    {
        buf[i] = '0' + abs(num % 10);
        num /= 10;
    }
    buf[i] = '\0';
}


void hex_to_str(char *buf, unsigned int num)
{
    int i = 0;

    if (num == 0)
        buf[i++] = '0';

    for (; num; i++)
    {
        int digit = num % 16;
        buf[i] = digit < 10 ? '0' + digit : 'a' + digit - 10;
        num /= 16;
    }
    buf[i] = '\0';
}


int get_spec(char *s)
{
    char *p;
    if ((p = my_strchr(s, '%')) != NULL)
    {
        p++;
        if (*p == 'd')
            return 1;
        else if (*p == 'l' && *(p + 1) == 'd')
            return 2;
        else if (*p == 's')
            return 3;
        else if (*p == 'x')
            return 4;
        else if (*p == '%')
            return 5;
    }
    else
        return 0;

    return FORMAT_ERR;
}

int insert_num_str(char *buf, const char *src, int pos, int max_len)
{
    int insert_len = 0;
    size_t num_len = my_strlen(src);
    for (; num_len > 0; num_len--)
    {
        if (buf && pos < max_len - 1)
            buf[pos++] = src[num_len - 1];
        insert_len++;
    }
    return insert_len;
}

int insert_sign(char *buf, size_t pos, bool flag, size_t max_len)
{
    int add_sign = 0;
    if (buf && pos < max_len - 1 && flag)
        buf[pos++] = '-';
    if (flag)
        add_sign++;

    return add_sign;
}

int insert_arg_by_spec(char *buf, va_list params, int sp, size_t n)
{
    char temp[MAX_NUM_LEN];
    size_t i = my_strlen(buf);
    int insert_len = 0;

    if (sp == 1)
    {
        int num = va_arg(params, int);

        insert_len = insert_sign(buf, i, num < 0, n);
        i += insert_len;

        int_to_str(temp, num);
    }
    else if (sp == 2)
    {
        long num = va_arg(params, long int);

        insert_len = insert_sign(buf, i, num < 0, n);
        i += insert_len;

        long_to_str(temp, num);
    }
    else if (sp == 3)
    {
        char *s = va_arg(params, char*);
        insert_len += my_strncat(buf, s, my_strlen(s), n);
    }
    else if (sp == 4)
    {
        unsigned int num = va_arg(params, unsigned int);
        hex_to_str(temp, num);
    }
    else if (sp == 5)
        insert_len += my_strncat(buf, "%", 1, n);

    if (sp == 1 || sp == 2 || sp == 4)
        insert_len += insert_num_str(buf, temp, i, n);

    return insert_len;
}


int my_snprintf(char *restrict buf, size_t n, char *restrict format, ...)
{
    if (n > INT_MAX)
        return OVERFLOW;

    if (format == NULL)
        return -1;

    va_list params;
    va_start(params, format);

    init_zeros(buf, n);

    int req_len = 0;
    for (int sp = get_spec(format); sp != 0; sp = get_spec(format))
    {
        char *temp = my_strchr(format, '%');
        req_len += my_strncat(buf, format, temp - format, n);

        format = sp == 2 ? temp + 3 : temp + 2;
        req_len += insert_arg_by_spec(buf, params, sp, n);
    }
    req_len += my_strncat(buf, format, my_strlen(format), n);

    va_end(params);

    return req_len;
}
