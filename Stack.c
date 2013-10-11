#include "structs.h"
#include <stdio.h>

struct StackNode *Stack;
int count;

void init() 
{
    Stack = NULL;
    count = 0;
}

struct StackNode *peek()
{
    return Stack;
}

void push(/*data*/)
{
    struct StackNode *curr_node = Stack;
    struct StackNode *new_node = NULL;

    new_node = (struct StackNode*)malloc(sizeof(struct StackNode));
    new_node->next = Stack;
    Stack = new_node;
    ++count;
}

void pop()
{
    if (Stack == NULL) return;

    struct StackNode *curr_node = Stack;
    Stack = Stack->next;  
    free(curr_node);
    --count;
}

void delete_stack()
{
    struct StackNode *curr_node = Stack,
                                *next_node = NULL;
    while (curr_node != NULL)
    {
        next_node = curr_node->next;
        free(curr_node);
        curr_node = next_node;
    }
    count = 0;
    Stack = NULL;
}

int main()
{
    int i;
    init();
    printf("count: %d\n", count);
    for (i = 0; i < 100000; ++i)
        push();
    printf("count: %d\n", count);
    for (i = 0; i < 100000; ++i)
    {
        if ((i % 3) == 0)
            pop();
    }
    printf("count: %d\n", count);
    delete_stack();
    printf("count: %d\n", count); 
    return 0;
}
