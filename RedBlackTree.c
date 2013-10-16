#include "structs.h"
#include <stdio.h>

struct RedBlackTreeNode *RedBlackTree;
int count;

void init()
{
    RedBlackTree = NULL;
    count = 0;
}

struct RedBlackTreeNode *get_grandparent(struct RedBlackTreeNode *node)
{
    if ((node != NULL) && (node->parent != NULL))
    {
        return node->parent->parent;
    }
    else
        return NULL;
}

struct RedBlackTreeNode *get_uncle(struct RedBlackTreeNode *node)
{
    struct RedBlackTreeNode *gp = get_grandparent(node);
    if (gp == NULL)
    {
        return NULL;
    }
    if (node->parent == gp->left)
    {
        return gp->right;
    }
    else
    {
        return gp->left;
    }
}

/* Do not call this function when the node is the root of the tree because the parent will be NULL */
struct RedBlackTreeNode *get_sibling(struct RedBlackTreeNode *node)
{
    if (node == node->parent->left)
    {
        return node->parent->right;
    }
    else
    {
        return node->parent->left;
    }
}

void left_rotate(struct RedBlackTreeNode *node)
{
    struct RedBlackTreeNode *temp_node;
    temp_node = node->right;
    
    node->right = temp_node->left;
    if (temp_node->left != NULL)
    {
        temp_node->left->parent = node;
    }
    temp_node->parent = node->parent;
    if (node->parent == NULL)
    {
        RedBlackTree = temp_node;
    }
    else
    {
        if (node == (node->parent)->left)
        {
            node->parent->left = temp_node;
        }
        else
        {
            node->parent->right = temp_node;
        }
    }
    temp_node->left = node;
    node->parent = temp_node;
}

void right_rotate(struct RedBlackTreeNode *node)
{
    struct RedBlackTreeNode *temp_node;
    temp_node = node->left;

    node->left = temp_node->right;
    if (temp_node->right != NULL)
    {
        temp_node->right->parent = node;
    }
    temp_node->parent = node->parent;
    if (node->parent == NULL)
    {
        RedBlackTree = temp_node;
    }
    else
    {
        if (node == (node->parent)->right)
        {
            node->parent->right = temp_node;    
        }
        else
        {
            node->parent->left = temp_node;
        }
    }
    temp_node->right = node;
    node->parent = temp_node;
}

void insert(/*data*/)
{
    struct RedBlackTreeNode *new_node;
    new_node = (struct RedBlackTreeNode*)malloc(sizeof(struct RedBlackTreeNode));
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;


}

int main()
{

    return 0;
}
