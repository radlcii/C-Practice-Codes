/* This program was written to test the various data structures coded.
 * It was written by Robert De La Cruz II on Jan 5, 2019.
 *
 * Last editied Jan 6, 2019
 *
 * The following files need to be present, compiled and linked foor this to run:
 * main.c (this file)
 * node.c
 * Node_Interface.h
 * SSL.c
 * SSL_Interface.h
 *
 * I used make and a makefile which was obtained from a StackOverflow comment by user Joey Adams: https://stackoverflow.com/a/1484873
 *
 * A HUGE thanks to posters on StackOverflow, http://www.icosaedro.it/c-modules.html, and others whom I found through google and failed to cite.
 *
 */

#include<stdio.h>
#include<stdlib.h>

#include"SSL_Interface.h"

int main(){
  int MAS = MAX_ARRAY_SIZE;
  int input = 1;
  printf("Would you like to test: (1): Singly Linked List\n");
  scanf("%d", &input);
  int testArr[MAS];

  /* Fill the test array */
  for(int i=0; i<MAS;i++){
    testArr[i] = i+1;
    printf("%d\t", testArr[i]);
    if(testArr[i] % 10 == 0){
      puts(" ");
    }
  }
  puts(" ");

  /*********************
  * Singly Linked List *
  *********************/
  if(input==1){
    int isHeadIns;
    printf("Would you like to test\n(1) Head Insert\n(2) Tail Insert\n(3) Mixed Insert?\n");
    scanf("%d", &isHeadIns);
    node *current = NULL;
    node *new = NULL;

    /* Dump test array data into nodes and form the linked list */
    for(int i=0; i<MAS; i++){
        new = createNode(&testArr[i]);
        if(head == NULL){
          head = tail = new;
        }
        else if (isHeadIns == 1){
          head = headInsert(head, new);
        }
        else if (isHeadIns == 2){
          tail = tailInsert(tail, new);
        }
        else if (isHeadIns == 3){
          if (testArr[i]%2 == 1) { head = headInsert(head, new); }
          else { tail = tailInsert(tail, new); }
        }
    }
    /* Print the Linked List */
    printList(head, printInt);

    /* Free the memory */
    SSL_Terminate(head);

    puts("Test completed successfully.  Exiting SSL.");
  }


  /******************
  * Erronious Input *
  ******************/
  else{
    puts("Invalid entry, exiting main.");
  }

  return 0;
}
