#include "../inc/list.h"

position init_pos(int pos, char *symb, node_t *node)
{
    position a;
    a.pos = pos;
    a.symb_pointer = symb;
    a.node = node;
    return a;
}

void free_list(node_t *a)
{
    node_t *buf = a;
    for (; buf; a = buf)
    {
        buf = a->next;
        free(a);
    }
}

node_t *find_last_good_node(node_t *a)
{
    for (; a; a = a->next)
        for (int i = 0; i < a->size; i++)
            if (a->store[i] == '\0')
                return a;
    return NULL;
}

void delete_and_resize_nodes(node_t *a)
{
    node_t *tail = find_last_good_node(a);
    if (tail->next)
        free_list(tail->next);

    tail->next = NULL;

    tail->size = 0;
    for (; tail->store[tail->size++] != '\0';);
}

bool move_pointer(position *pos)
{
    if (pos->pos + 1 == pos->node->size && pos->node->size != STORE_SIZE)
        return false;

    if (pos->pos == STORE_SIZE - 1)
    {
        if (pos->node->next == NULL)
            return false;

        pos->pos = 0;
        pos->symb_pointer = pos->node->next->store;
        pos->node = pos->node->next;
    }
    else
    {
        pos->pos++;
        pos->symb_pointer++;
    }

    return true;
}

void delete_double_spaces(node_t *a)
{
    bool flag = false;

    position cur = init_pos(0, a->store, a);
    position next = init_pos(1, a->store + 1, a);

    for (; *cur.symb_pointer != '\0';)
    {
        if (*cur.symb_pointer == ' ' && *next.symb_pointer == ' ')
        {
            for (; *next.symb_pointer == ' '; move_pointer(&next));
            flag = true;
        }
        else
        {
            move_pointer(&cur);
            if (flag)
                *cur.symb_pointer = *next.symb_pointer;
            move_pointer(&next);
        }
    }

    delete_and_resize_nodes(a);
}
// a  bcd  ef   gxhi jk  l     mno  qr

void concatenate(node_t *a, node_t *b)
{
    node_t *tail = a;
    for (; tail->next; tail = tail->next);

    tail->next = b;

    position cur = init_pos(tail->size - 1, tail->store + tail->size - 1, tail);
    position next = init_pos(0, b->store, b);

    tail->size = STORE_SIZE;

    for (; *next.symb_pointer != '\0';)
    {
        *cur.symb_pointer = *next.symb_pointer;
        move_pointer(&cur);
        move_pointer(&next);
    }
    *cur.symb_pointer = '\0';

    delete_and_resize_nodes(a);
}

bool check_substr(position *a, const char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] != *a->symb_pointer || !move_pointer(a))
            return false;
    return true;
}

int find_str(node_t *a, const char *s)
{
    position cur = init_pos(0, a->store, a);
    bool can_move = true;

    int k = 0;
    for (; can_move; k++)
    {
        position buf = cur;
        if (*cur.symb_pointer == s[0] && check_substr(&buf, s))
            return k;

        can_move = move_pointer(&cur);
    }
    return -1;
}