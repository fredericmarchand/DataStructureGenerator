all:	DoublyLinkedList SinglyLinkedList Stack Generator

Generator:			Generator.o
					gcc Generator.o -o Generator

Stack:				structs.h Stack.o
					gcc Stack.o -o Stack

DoublyLinkedList:	structs.h DoublyLinkedList.o
					gcc DoublyLinkedList.o -o DoublyLinkedList

SinglyLinkedList:	structs.h SinglyLinkedList.o
					gcc SinglyLinkedList.o -o SinglyLinkedList

Generator.o:		Generator.c
					gcc -c Generator.c -o Generator.o

Stack.o:			structs.h Stack.c
					gcc -c Stack.c -o Stack.o

DoublyLinkedList.o:	structs.h DoublyLinkedList.c
					gcc -c DoublyLinkedList.c -o DoublyLinkedList.o

SinglyLinkedList.o:	structs.h SinglyLinkedList.c
					gcc -c SinglyLinkedList.c -o SinglyLinkedList.o

clean:
			rm -rf *.o SinglyLinkedList DoublyLinkedList Stack Generator
