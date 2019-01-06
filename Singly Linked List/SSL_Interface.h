/*
 * Interface for the modular Singly Linked List, written for personal edification.
 * Written by Robert De la Cruz II
 * Written on Jan 6, 2019.
 * Written in the "Ubuntu in Windows 10" app in Vim, compiled using GNU make 4.1
 *
 * This file depends on the following files to work:
 * main.c
 * node.c
 * Node_Interface.h
 * SSL.c
 *
 * Last edited on Jan 6, 2019
 *
 * A HUGE thanks to posters on StackOverflow, http://www.icosaedro.it/c-modules.html, and others whom I found through google and failed to cite.
 */

#ifndef SSL_Interface_H
#define SSL_Interface_H


/* System headers */
#include<stdlib.h>


/* Other application headers */
#include"Node_Interface.h"


/* set EXTERN macro */
#ifndef SSL_Interface_IMPORT
  #define EXTERN
#else
  #define EXTERN extern
#endif


/************
* Constants *
************/
#define MAX_ARRAY_SIZE 100

/********
* Types *
********/
typedef struct node{
  void *data;
  struct node *link0;
}node;


/*******************
* Global Variables *
*******************/
EXTERN node *head;
EXTERN node *tail;
EXTERN void *data;
EXTERN void *funptr;


/*******************
* Function headers *
*******************/

/**
 * Initializes this module.
 * Should be called only once in main()
 */
EXTERN void SSL_Init(void);

/**
 * Releases memory used by each node in SSL
 * Should be called in main() when operations have finished
 * @Param head of the list
 */
EXTERN void SSL_Terminate(node *head);


/**
 * Helper methods for printList
 * @Param data within the nodes
 */
EXTERN void printInt(void *data);
EXTERN void printChar(void *data);

/**
 * Prints the SSL in order from the head node until the end.
 * It is printed to the stdout.
 * @Param node *current initially sent the head node of the list
 * @Param function pointer for the data type to be presented
 * */
EXTERN void printList(node *current, void (*funptr) (void*));

/**
 * Performs a search for the supplied value starting from the head.
 * @Param head of the list
 * @Param sample data to be the search key
 */
EXTERN node* basicSearch(node *current, void *d);

/**
 * Inserts a node at the head (front) of the list
 * @Param head of the ist
 * @Param new node, taken from createNode()
 * @Return a pointer to the new head of the list
 */
EXTERN node* headInsert(node *head, node *n);

/**
 * Inserts a node at the tail (end) of the list
 * @Param tail of the list (pointer variable provided)
 * @Param new node taken from createNode()
 * @Return a pointer to the new tail of the list
 */
EXTERN node* tailInsert(node *tail, node *n);

/**
 * Creates a node struct
 * @Param void pointer to data that the node will contain
 * @Return a pointer to the node created
 */
EXTERN node* createNode(void *d);

/**
 * Deletes a node from the list and frees its memory
 * @Param head of the list
 * @Param pointer to data to be the search key
 */
EXTERN void deleteNode(node *head, void *d);

#undef SSL_Interface_IMPORT
#undef EXTERN
#endif

