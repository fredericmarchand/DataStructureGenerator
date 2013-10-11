#include "structs.h"
#include <stdio.h>

struct QueueNode *Queue;
struct QueueNode *last;
int count;

void init() 
{
    Queue = NULL;
    last = Queue;
    count = 0;
}

struct QueueNode *first()
{
    return Queue;
}

struct QueueNode *get_last()
{
    return last;
}

void push(/*data*/)
{
    struct QueueNode *new_node = NULL;
    new_node = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (Queue == NULL)
    {
        new_node->next = NULL;
        new_node->prev = NULL;
        Queue = new_node;
        last = new_node;
        count = 1;
    }
    else
    {
        new_node->prev = NULL;
        new_node->next = Queue;
        Queue->prev = new_node;
        Queue = new_node;
        ++count;
    }
}

void pop()
{
    if (last == NULL) return;

    struct QueueNode *temp_node = last;
    temp_node->prev->next = NULL;
    last = last->prev;
    free(temp_node);
    --count;
}

void delete_list()
{
    struct QueueNode *curr_node = Queue,
                                *next_node = NULL;
    while (curr_node != NULL)
    {
        next_node = curr_node->next;
        free(curr_node);
        curr_node = next_node;
    }
    count = 0;
    Queue = NULL;
}

int size()
{
    return count;
}

int main()
{
    int i;
    init();
    printf("count: %d\n", count);
    for (i = 0; i < 100000; ++i)
        push();
    printf("count: %d\n", count);
    for (i = 0; i < 10000; ++i)
        pop();
    printf("count: %d\n", count);
    delete_list();
    printf("count: %d\n", count); 
    return 0;
}
