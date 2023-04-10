#include "../inc/my_snprintf.h"


int main(void)
{
    char *s = "C is good";
    int a = -9924545;
    long b = -5876786897;
    int len1, len2;

    len1 = my_snprintf(NULL, 0, "Hello %d %ld %% %s", a, b, s);
    len2 = snprintf(NULL, 0, "Hello %d %ld %% %s", a, b, s);


    len1++;
    len2++;
    char *s1 = malloc(len1 * sizeof(char));
    char *s2 = malloc(len2 * sizeof(char));

    my_snprintf(s1, len1, "Hello %d %ld %% %s", a, b, s);
    snprintf(s2, len2, "Hello %d %ld %% %s", a, b, s);
    printf("my_snprintf = %s\nsnprintf = %s\n", s1, s2);
    printf("my_len = %d\nlen = %d\n", len1, len2);

    free(s1);
    free(s2);

    return OK;
}
