#include <stdio.h>
#include <stdlib.h>

typedef struct _listNode {
    int data;
    struct _listNode *next;
}listNode;

typedef struct _queue {
    listNode *head;
    listNode *tail;
}queue;

// Primary operations
void enqueue(queue **node, int data);
listNode* dequeue(queue **node);
void traverse(queue *node);

// Secondary operations
int isEmpty(queue *node);
