#include "structs.h"
#include <stdio.h>

void insert_case1(struct RedBlackTreeNode *node);
void insert_case2(struct RedBlackTreeNode *node);
void insert_case3(struct RedBlackTreeNode *node);
void insert_case4(struct RedBlackTreeNode *node);
void insert_case5(struct RedBlackTreeNode *node);
void delete_case1(struct RedBlackTreeNode *node);
void delete_case2(struct RedBlackTreeNode *node);
void delete_case3(struct RedBlackTreeNode *node);
void delete_case4(struct RedBlackTreeNode *node);
void delete_case5(struct RedBlackTreeNode *node);
void delete_case6(struct RedBlackTreeNode *node);

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

int get_black_height(struct RedBlackTreeNode *node)
{
    struct RedBlackTreeNode *temp = node;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->color == BLACK)
        {
            ++count;
        }
        temp = temp->parent;
    }
    return count;
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

void rotate_left(struct RedBlackTreeNode *node)
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

void rotate_right(struct RedBlackTreeNode *node)
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
    new_node->color = RED;

    if (RedBlackTree == NULL)
    {
        RedBlackTree = new_node;
    }
    else
    {
        struct RedBlackTreeNode *temp = RedBlackTree;
        if (temp->left == NULL)
        {
            
        }
    }
    insert_case1(new_node);
}

void insert_case1(struct RedBlackTreeNode *node)
{
    /* Check if the node is the root of the tree */
    if (node->parent == NULL)
    {
        /* If it is recolor it to black */
        node->color = BLACK;
    }
    else
    {
        insert_case2(node);
    }
}

void insert_case2(struct RedBlackTreeNode *node)
{
    if (node->parent->color == BLACK)
    {
        return; /* Nothing to do */
    }
    else
    {
        insert_case3(node);
    }
}

void insert_case3(struct RedBlackTreeNode *node)
{
    struct RedBlackTreeNode *uncle = get_uncle(node),
                            *gp = NULL;

    /* Check if the uncle is a red node */
    if ((uncle != NULL) && (uncle->color == RED))
    {
        node->parent->color = BLACK;
        uncle->color = BLACK;
        gp = get_grandparent(node);
        gp->color = RED;
        insert_case1(gp);
    }
    else
    {
        insert_case4(node);
    }
}

void insert_case4(struct RedBlackTreeNode *node)
{
    struct RedBlackTreeNode *gp = get_grandparent(node);

    if ((node == node->parent->right) && (node->parent == gp->left))
    {
        rotate_left(node->parent);
        node = node->left;
    }
    else if ((node == node->parent->left) && (node->parent == gp->right))
    {
        rotate_right(node->parent);
        node = node->right;
    }
    insert_case5(node);
}

void insert_case5(struct RedBlackTreeNode *node)
{
    struct RedBlackTreeNode *gp = get_grandparent(node);

    node->parent->color = BLACK;
    gp->color = RED;
    if (node == node->parent->left)
    {
        rotate_right(gp);
    }
    else
    {
        rotate_left(gp);
    }
}

void delete(struct RedBlackTreeNode *node)
{
    
}

void delete_case1(struct RedBlackTreeNode *node)
{
    if (node->parent != NULL)
    {
        delete_case2(node);
    }
}

void delete_case2(struct RedBlackTreeNode *node)
{
    struct RedBlackTreeNode *sibling = get_sibling(node);

    if (sibling->color == RED)
    {
        node->parent->color = RED;
        sibling->color = BLACK;
        if (node == node->parent->left)
        {
            rotate_left(node->parent);
        }
        else
        {
            rotate_right(node->parent);
        }
    }
    delete_case3(node);
}

void delete_case3(struct RedBlackTreeNode *node)
{
    struct RedBlackTreeNode *sibling = get_sibling(node);

    if ((node->parent->color == BLACK) &&
        (sibling->color == BLACK) &&
        (sibling->left->color == BLACK) &&
        (sibling->right->color == BLACK))
    {
        sibling->color = RED;
        delete_case1(node->parent);
    }
    else
    {
        delete_case4(node);   
    }
}

void delete_case4(struct RedBlackTreeNode *node)
{
    struct RedBlackTreeNode *sibling = get_sibling(node);

    if ((node->parent->color == RED) &&
        (sibling->color == BLACK) &&
        (sibling->left->color == BLACK) &&
        (sibling->right->color == BLACK))
    {
        sibling->color = RED;
        node->parent->color = BLACK;
    }
    else
    {
        delete_case5(node);
    }
}

void delete_case5(struct RedBlackTreeNode *node)
{
    struct RedBlackTreeNode *sibling = get_sibling(node);

    if (sibling->color == BLACK)
    {
        if ((node == node->parent->left) &&
            (sibling->right->color == BLACK) &&
            (sibling->left->color == RED))
        {
            sibling->color = RED;
            sibling->left->color = BLACK;
            rotate_right(sibling);
        }
        else if ((node == node->parent->right) &&
                 (sibling->left->color == BLACK) &&
                 (sibling->right->color == RED))
        {
            sibling->color = RED;
            sibling->right->color = BLACK;
            rotate_left(sibling);
        }   
    }
    delete_case6(node);
}

void delete_case6(struct RedBlackTreeNode *node)
{
    struct RedBlackTreeNode *sibling = get_sibling(node);

    sibling->color = node->parent->color;
    node->parent->color = BLACK;

    if (node == node->parent->left)
    {
        sibling->right->color = BLACK;
        rotate_left(node->parent);
    }
    else
    {
        sibling->left->color = BLACK;
        rotate_right(node->parent);
    }
}

int main()
{

    return 0;
}
