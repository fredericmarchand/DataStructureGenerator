#include "structs.h"
#include <stdio.h>

struct DoublyLinkedListNode *DoublyLinkedList;
struct DoublyLinkedListNode *last;
int count;

void init() 
{
    DoublyLinkedList = NULL;
    last = DoublyLinkedList;
    count = 0;
}

void add_to_back(/*data*/)
{
    struct DoublyLinkedListNode *curr_node = DoublyLinkedList;
    struct DoublyLinkedListNode *new_node = NULL;

    new_node = (struct DoublyLinkedListNode*)malloc(sizeof(struct DoublyLinkedListNode));

    if (DoublyLinkedList == NULL)
    {
        new_node->next = NULL;
        new_node->prev = NULL;
        DoublyLinkedList = new_node;
        last = new_node;
        count = 1;
    }
    else 
    {
        last->next = new_node;
        new_node->prev = last;
        new_node->next = NULL;
        last = new_node;
        ++count;
    }
}

void add_to_front(/*data*/)
{
    struct DoublyLinkedListNode *new_node = NULL;
    new_node = (struct DoublyLinkedListNode*)malloc(sizeof(struct DoublyLinkedListNode));
    if (DoublyLinkedList == NULL)
    {
        new_node->next = NULL;
        new_node->prev = NULL;
        DoublyLinkedList = new_node;
        last = new_node;
        count = 1;
    }
    else
    {
        new_node->prev = NULL;
        new_node->next = DoublyLinkedList;
        DoublyLinkedList->prev = new_node;
        DoublyLinkedList = new_node;
        ++count;
    }
}

struct DoublyLinkedListNode *get(int index)
{
    if (DoublyLinkedList == NULL) return NULL;
    if (index >= count) return NULL;
    int i = 0, j;
    struct DoublyLinkedListNode *temp_node;
    if (index < count / 2)
    {
        temp_node = DoublyLinkedList;
        for (j = 0; j <= index; ++j)
        {
            temp_node = temp_node->next;
        }
    }
    else
    {
        temp_node = last;
        for (j = count-1; j >= index; --j)
        {
            temp_node = temp_node->prev;
        }
    }
    return temp_node;
}

void remove_by_index(int i)
{
    if (DoublyLinkedList == NULL) return;
    if (i >= count) return;

    struct DoublyLinkedListNode *temp_node = get(i);
    temp_node->prev->next = temp_node->next;
    temp_node->next->prev = temp_node->prev;
    free(temp_node);
    --count;
}

void delete_list()
{
    struct DoublyLinkedListNode *curr_node = DoublyLinkedList,
                                *next_node = NULL;
    while (curr_node != NULL)
    {
        next_node = curr_node->next;
        free(curr_node);
        curr_node = next_node;
    }
    count = 0;
    DoublyLinkedList = NULL;
}

int getCount()
{
    return count;
}

int main()
{
    int i;
    init();
    printf("count: %d\n", count);
    for (i = 0; i < 100000; ++i)
        add_to_front();
    printf("count: %d\n", count);
    for (i = 0; i < 100000; ++i)
        add_to_back();
    printf("count: %d\n", count);

    for (i = 0; i < 200000; ++i)
    {
        if ((i % 2) == 0)
            remove_by_index(i);
    }
    printf("count: %d\n", count);
    delete_list();
    printf("count: %d\n", count); 
    return 0;
}
