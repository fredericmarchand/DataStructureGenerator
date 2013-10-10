#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>

extern int optind;
extern char *optarg;

char *get_help_string()
{
    return "\
-n, --name <argument>\t\tName of the data structure\n\
-l, --singlylinkedlist\t\tCreate a Singly Linked List\n\
-d, --doublylinkedlist\t\tCreate a Doubly Linked List\n\
-s, --stack\t\t\tCreate a Stack\n\
-h, --help\t\t\tPrint this help string\n\
";
}

int main(int argc, char *argv[])
{
    int opt;
    int option_index = 0;
    static struct option long_options[] =
    {
        {"name",              required_argument, 0, 'n'},
        {"singlylinkedlist",  no_argument,       0, 'l'},
        {"doublylinkedlist",  no_argument,       0, 'd'},
        {"stack",             no_argument,       0, 's'},
        {"help",              no_argument,       0, 'h'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "n:lds", long_options, &option_index)) != -1)
    {
        switch (opt)
        {
            case 'n': 

                break;
            case 'l':

                break;
            case 'd':

                break;
            case 's':

                break;
            case 'h':
                printf("%s", get_help_string());
                return;
            case '?':
                /*Error message printed out by getopt_long*/
                break;
        }
    }
    return 0;
}
