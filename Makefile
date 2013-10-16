all:	DoublyLinkedList SinglyLinkedList Stack Queue Generator RedBlackTree

Generator:			Generator.o
					gcc Generator.o -o Generator

Stack:				structs.h Stack.o
					gcc Stack.o -o Stack

DoublyLinkedList:	structs.h DoublyLinkedList.o
					gcc DoublyLinkedList.o -o DoublyLinkedList

SinglyLinkedList:	structs.h SinglyLinkedList.o
					gcc SinglyLinkedList.o -o SinglyLinkedList

Queue:				structs.h Queue.o
					gcc Queue.o -o Queue

RedBlackTree:		structs.h RedBlackTree.o
					gcc RedBlackTree.o -o RedBlackTree

Generator.o:		Generator.c
					gcc -c Generator.c -o Generator.o

Stack.o:			structs.h Stack.c
					gcc -c Stack.c -o Stack.o

DoublyLinkedList.o:	structs.h DoublyLinkedList.c
					gcc -c DoublyLinkedList.c -o DoublyLinkedList.o

SinglyLinkedList.o:	structs.h SinglyLinkedList.c
					gcc -c SinglyLinkedList.c -o SinglyLinkedList.o

Queue.o:			structs.h Queue.c
					gcc -c Queue.c -o Queue.o

RedBlackTree.o:		structs.h RedBlackTree.c
					gcc -c RedBlackTree.c -o RedBlackTree.o

clean:
			rm -rf *.o SinglyLinkedList DoublyLinkedList Stack Queue RedBlackTree Generator
