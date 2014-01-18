#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include <ctype.h>

#include "structs.h"

extern int optind;
extern char *optarg;

char *get_help_string()
{
    return "\
-n, --name <argument>\t\tName of the data structure\n\
-l, --singlylinkedlist\t\tCreate a Singly Linked List\n\
-d, --doublylinkedlist\t\tCreate a Doubly Linked List\n\
-s, --stack\t\t\tCreate a Stack\n\
-q, --queue\t\t\tCreate a Queue\n\
-u, --deque\t\t\tCreate a Deque\n\
-r, --rbtree\t\t\tCreate a Red-Black Tree\n\
-b, --btree\t\t\tCreate a B-tree\n\
-t, --bstree\t\t\tCreate a Binary Search Tree\n\
-p, --heap\t\t\tCreate a Heap\n\
-m, --hashmap\t\t\tCreate a HashMap\n\
-h, --help\t\t\tPrint this help string\n\
\n\
Example:\t./Generator --name my_list --doublylinkedlist\n\
";
}

int main(int argc, char *argv[])
{
    int opt;
    int option_index = 0;

    char * name = "";
    int dts = -1;

    static struct option long_options[] =
    {
        {"name",              required_argument, 0, 'n'},
        {"singlylinkedlist",  no_argument,       0, 'l'},
        {"doublylinkedlist",  no_argument,       0, 'd'},
        {"stack",             no_argument,       0, 's'},
        {"queue",             no_argument,       0, 'q'},
        {"deque",             no_argument,       0, 'u'},
        {"rbtree",            no_argument,       0, 'r'},
        {"btree",             no_argument,       0, 'b'},
        {"bstree",            no_argument,       0, 't'},
        {"heap",              no_argument,       0, 'p'},
        {"hashmap",           no_argument,       0, 'm'},
        {"help",              no_argument,       0, 'h'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "n:lds", long_options, &option_index)) != -1)
    {
        switch (opt)
        {
            case 'n': /* name */
                strcpy (name, optarg);
                break;
            case 'l': /* singly linked list */
                dts = SINGLYLINKEDLIST;
                break;
            case 'd': /* doubly linked list */
                dts = DOUBLYLINKEDLIST;
                break;
            case 's': /* stack */
                dts = STACK;
                break;
            case 'q': /* queue */
                dts = QUEUE;
                break;
            case 'u': /* deque */
                dts = DEQUE;
                break;
            case 'r': /* red-black tree */
                dts = REDBLACKTREE;
                break;
            case 'b': /* b-tree */ 
                dts = BTREE;
                break;
            case 't': /* binary search tree */
                dts = BINARYSEARCHTREE;
                break;
            case 'p': /* heap */
                dts = HEAP;
                break;
            case 'm': /* hash map */
                dts = HASHMAP;
                break;
            case 'h': /* help */
                printf("%s", get_help_string());
                return 0;
            case '?':
                /*Error message printed out by getopt_long*/
                if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
                return 1;
        }
    }

    if (dts == -1)
    {
        printf("Please select a data structure to build\n");
    }


    return 0;
}
