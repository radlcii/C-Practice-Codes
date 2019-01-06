/* 
 * This is a generic modular node struct for use in multiple simple data structure programs.
 * There likely are more efficient ways to do this, but the use of a more modular method is for personal edification.
 * Written by Robert De La Cruz II on Dec 31, 2018.
 * 
 * Written in the "Ubuntu in Windows 10" app in Vim, compiled using GNU make 4.1
 *
 * Last edited Jan 6, 2019
 */

#ifndef NODE
#define NODE

typedef struct node{
  void *data;
  struct node *link0;
  struct node *link1;
}node;

#endif

