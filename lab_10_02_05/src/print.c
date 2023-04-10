#include "../inc/print.h"

void print_node(node_t *a)
{
    for (int i = 0; i < a->size && a->store[i] != '\0'; i++)
        printf("%c", a->store[i]);
}

void print_list(node_t *a)
{
    for (; a; a = a->next)
        print_node(a);
    printf("\n");
}

