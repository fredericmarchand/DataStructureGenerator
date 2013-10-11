#include <stdlib.h>
#include <string.h>
#include <stdio.h>

enum node_color {
    BLACK = 0,
    RED   = 1
};

struct SinglyLinkedListNode {
    struct SinglyLinkedListNode *next;
};

struct DoublyLinkedListNode {
    int index;
    struct DoublyLinkedListNode *next;
    struct DoublyLinkedListNode *prev;
};

struct BinaryTreeNode {
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

struct RedBlackTreeNode {
    struct RedBlackTreeNode *left;
    struct RedBlackTreeNode *right;
    enum node_color color;
};

struct StackNode {
    struct StackNode *next;
};

struct QueueNode {
    struct QueueNode *next;
    struct QueueNode *prev;
};
