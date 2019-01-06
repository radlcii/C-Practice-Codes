/*
 * This is a modular Singly Linked List implementations file.
 * Written by Robert De La Cruz II
 * Written on Dec 31, 2018.
 * Written in the "Ubuntu in Windows 10" app in Vim, compiled using GNU make 4.1
 *
 * To function, this file depends on the presence of the following files: 
 * main.c
 * node.c
 * Node_Interface.h
 * SSL_Interface.h
 *
 * A HUGE thanks to posters on StackOverflow, http://www.icosaedro.it/c-modules.html, and others whom I found through google and failed to cite.
 *
 * Last Updated Jan 6, 2019
 */

#include<stdio.h>
#include<stdlib.h>
#include"Node_Interface.h"

#define SSL_Import
#include"SSL_Interface.h"

/************
* Variables *
************/

static int DATA_SIZE;
static int NODE_SIZE;

/*******************
* Public functions *
*******************/

void printInt(void *data){
  printf("%d\t", *(int *)data);
}

void printChar(void *data){
  printf("%c\t", *(char *)data);
}

void printList(node *current, void (*funptr) (void*)){
  while(current != NULL){
    for(int i=0; i<10; i++){
      (*funptr)(current->data);
      current = current->link0;
    }
    puts(" ");
  }
  puts(" ");
}

node* basicSearch(node *current, void *d){
  while(current != NULL) {
    if(current->data == d){
      puts("Found it!");
      return current;
    }
  }
  puts("Query not found.");
}

node* headInsert(node *head, node *n){
  n->link0 = head;
  head = n;
  return head;
}

node* tailInsert(node *tail, node *n){
  tail->link0 = n;
  tail = n;
  return tail;
}

node* createNode (void *d){
  DATA_SIZE = sizeof(*d);
  NODE_SIZE = DATA_SIZE + sizeof(node);
  node* new = malloc(NODE_SIZE);
  new->data = d;
  new->link0 = NULL;
  return new;
}

void deleteNode(node *head, void *d){
  node *target = basicSearch(head, d);
  if(target != NULL){
    free(target);
    puts("Query deleted.");
  }
}

void SSL_Init(){
  DATA_SIZE = 0;
  NODE_SIZE = 0;
  node *head = NULL;
  node *tail = NULL;
  void *data = NULL;
}

void SSL_Terminate(node *head){
  puts("Deleting List");
  node *current;
  while(head != NULL){
    current = head;
    head = head->link0;
    free(current);
  }
}

