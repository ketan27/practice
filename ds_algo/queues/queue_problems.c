#include "queue.h"

int main()
{
    int i;
    queue *node = (queue*)malloc(sizeof(queue));
    node->head = (listNode*)malloc(sizeof(listNode));
    node->tail = (listNode*)malloc(sizeof(listNode));
    node->head = NULL;
    node->tail = NULL;

    listNode *tmp = NULL;

    for (i = 0; i < 10; ++i) {
        enqueue(&node, i);
    }

    traverse(node);

    for (i = 0; i < 4; ++i) {
        tmp = dequeue(&node);
        free(tmp);
        traverse(node);
    }

    return 0;
}
