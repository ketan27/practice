#include "queue.h"

void enqueue(queue **node, int data)
{
    listNode *tmp = (listNode *)malloc(sizeof(listNode));
    tmp->data = data;
    tmp->next = NULL;
/*
    if ((*node)->tail)
        (*node)->tail->next = tmp;

    (*node)->tail = tmp;

    if ((*node)->head == NULL)
        (*node)->head = (*node)->tail;
        */

    if ((*node)->head == NULL) {
        (*node)->head = tmp;
        (*node)->tail = tmp;
        return;
    }

    (*node)->tail->next = tmp;
    (*node)->tail = tmp;
}

listNode* dequeue(queue **node)
{
    if ((*node)->head == NULL) {
        printf("Queue is empty\n");
        return NULL;
    }

    listNode *tmp = (listNode *)malloc(sizeof(listNode));
    tmp = (*node)->head;
    (*node)->head = (*node)->head->next;

    return tmp;
}

void traverse(queue *node)
{
    listNode *iter = node->head;

    while (iter) {
        printf("%d -> ", iter->data);
        iter = iter->next;
    }

    printf("\n");
}

