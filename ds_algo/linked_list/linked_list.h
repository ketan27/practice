#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define ERROR 1

#ifdef DBG
#define ENTER_MSG printf("%s() called\n", __func__)
#else
#define ENTER_MSG
#endif

/******************** SINGLE LINKED LIST ***************************/
extern int SLL_SIZE;
typedef struct _sll_node {
    int data;
    struct _sll_node *next;
}sll_node;

sll_node *create_sll_node(int data);

/* pos value depicts where node gets inserted:
 * 0 - begining.
 * Any +ve no.: At that place.
 * If no. is greater than the size, then at the end.
 */
int add_node_to_sll(int pos, sll_node **head, int data);

int traverse_sll(sll_node *head);

/* pos value denotes from where deletion needs to be done:
 * 0 - beginning (if exists)
 * any +ve no. : From that place if it exists, else quit
 */
int delete_node_from_sll(int pos, sll_node **head);

/******************** DOUBLY LINKED LIST ***************************/
typedef struct _dll_node {
    int data;
    struct _dll_node *prev;
    struct _dll_node *next;
}dll_node;

dll_node *create_dll_node(int data);

int add_node_to_dll(int pos, dll_node **head, int data);

int delete_node_from_dll(int pos, dll_node **head);

int traverse_dll(dll_node *head);
