#include "../inc/list.h"

node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void*))
{
    for (; head; head = head->next)
        if (comparator(data, head->data) == 0)
            return head;
    return NULL;
}

void insert(node_t **head, node_t *elem, node_t *before)
{
    if (!head || !elem)
        return;

    if (*head == before)
    {
        elem->next = *head;
        *head = elem;
        return;
    }

    node_t *node = *head;
    for (; node && node->next != before; node = node->next);

    if (node == NULL)
        return;

    node->next = elem;
    elem->next = before;
}

void append(node_t **head_a, node_t **head_b)
{
    if (!*head_a)
        *head_a = *head_b;
    else
    {
        node_t *cur = *head_a;
        for (; cur->next; cur = cur->next);
        cur->next = *head_b;
    }

    *head_b = NULL;
}

int list_size(node_t *head)
{
    int size = 0;

    for (; head; head = head->next, size++);

    return size;
}

void front_back_split(node_t *head, node_t **back)
{
    int size = list_size(head);
    node_t *buf = head;

    int half_size = size / 2 + size % 2 - 1;

    for (int i = 0; buf && i < half_size; buf = buf->next, i++);

    if (buf)
    {
        *back = buf->next;
        buf->next = NULL;
    }
    else
        *back = NULL;
}

void move_node(node_t **from, node_t **result, node_t **end)
{
    node_t *buf = *from;
    *from = (*from)->next;
    buf->next = NULL;

    if (*end)
        (*end)->next = buf;
    else
        *result = buf;

    *end = buf;
}

node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *))
{
    if (!head_a || !head_b || !comparator)
        return NULL;

    node_t *result = NULL;
    node_t *end = NULL;

    for (; *head_a || *head_b;)
    {
        if (!*head_a)
            move_node(head_b, &result, &end);
        else if (!*head_b)
            move_node(head_a, &result, &end);
        else if (comparator((*head_a)->data, (*head_b)->data) < 0)
            move_node(head_a, &result, &end);
        else
            move_node(head_b, &result, &end);
    }

    return result;
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
        return head;

    node_t *back;

    front_back_split(head, &back);

    head = sort(head, comparator);
    back = sort(back, comparator);

    return sorted_merge(&head, &back, comparator);
}
