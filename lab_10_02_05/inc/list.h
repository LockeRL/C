#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STORE_SIZE 4

typedef struct node node_t;

struct node
{
    char store[STORE_SIZE];
    int size;
    node_t *next;
};

typedef struct
{
    int pos;
    char *symb_pointer;
    node_t *node;
} position;

void delete_double_spaces(node_t *a);
void concatenate(node_t *a, node_t *b);
int find_str(node_t *a, const char *s);
void free_list(node_t *a);

#endif // LIST_H
