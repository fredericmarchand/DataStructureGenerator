#include "structs.h"
#include <stdio.h>

struct SinglyLinkedListNode *SinglyLinkedList;
int count;

void init() 
{
    SinglyLinkedList = NULL;
    count = 0;
}

void add(/*data*/)
{
    struct SinglyLinkedListNode *curr_node = SinglyLinkedList;
    struct SinglyLinkedListNode *new_node = NULL;

    new_node = (struct SinglyLinkedListNode*)malloc(sizeof(struct SinglyLinkedListNode));
    new_node->next = NULL;

    if (SinglyLinkedList == NULL)
    {
        SinglyLinkedList = new_node;
        count = 1;
    }
    else 
    {
        while (curr_node->next != NULL)
        {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
        ++count;
    }
}

void remove_by_index(int i)
{
    if (SinglyLinkedList == NULL) return;
    if (i >= count) return;

    struct SinglyLinkedListNode *curr_node = SinglyLinkedList,
                                *prev_node = NULL;
    if (i == 0)
    {
        SinglyLinkedList = SinglyLinkedList->next;
        free(curr_node);
        --count;
        return;
    }
    
    int index;
    for (index = 0; index < i; ++index)
    {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    
    prev_node->next = curr_node->next;
    free(curr_node);
    --count;
}

void delete_list()
{
    struct SinglyLinkedListNode *curr_node = SinglyLinkedList,
                                *next_node = NULL;
    while (curr_node != NULL)
    {
        next_node = curr_node->next;
        free(curr_node);
        curr_node = next_node;
    }
    count = 0;
    SinglyLinkedList = NULL;
}

int main()
{
    int i;
    init();
    printf("count: %d\n", count);
    for (i = 0; i < 1000; ++i)
        add();
    printf("count: %d\n", count);
    for (i = 0; i < 1000; ++i)
    {
        if ((i % 3) == 0)
            remove_by_index(i);
    }
    printf("count: %d\n", count);
    delete_list();
    printf("count: %d\n", count); 
    return 0;
}
