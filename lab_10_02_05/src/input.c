#include "../inc/input.h"

node_t *create_node(char *s)
{
    node_t *node = malloc(sizeof(node_t));
    if (!node)
        return NULL;

    node->size = copy_str(node->store, s, STORE_SIZE);
    node->next = NULL;

    return node;
}

node_t *create_list()
{
    char *s;
    size_t len = get_string(&s);
    if (len == 1)
    {
        free_str(&s);
        return NULL;
    }

    node_t *head = NULL;
    node_t *cur = NULL;
    node_t *buf = NULL;

    for (size_t i = 0; i < len && (buf = create_node(s + i)); i += STORE_SIZE, cur = buf)
    {
        if (i == 0)
            head = buf;
        else
            cur->next = buf;
    }

    free_str(&s);

    if (!buf)
    {
        free_list(head);
        return NULL;
    }

    return head;
}
