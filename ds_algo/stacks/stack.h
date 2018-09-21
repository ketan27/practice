#include <stdio.h>
#include <stdlib.h>

struct _stack_node {
    char data;
    struct _stack_node *next;
};
typedef struct _stack_node stack_node;

stack_node *createStackNode(char ch);
void push(stack_node **top, char ch);
char pop(stack_node **top);
char topNode(stack_node *top);
int isEmpty(stack_node *top);
void traverse(stack_node *top);
void deleteStack(stack_node **top);
int popUntil(stack_node **top, char ch);
