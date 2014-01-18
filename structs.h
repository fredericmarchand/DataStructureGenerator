#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SINGLYLINKEDLIST    1
#define DOUBLYLINKEDLIST    2
#define STACK               3
#define QUEUE               4
#define DEQUE               5
#define REDBLACKTREE        6
#define BTREE               7
#define BINARYSEARCHTREE    8
#define HEAP                9
#define HASHMAP             10

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
    struct BinaryTreeNode *parent;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

struct RedBlackTreeNode {
    struct RedBlackTreeNode *parent;
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
