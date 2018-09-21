#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *left;
    struct _node *right;
}node;

node* createNode(int val);
int insertNode(int val);
void traverse(node *root, short order);
int find(node *root, int val);
int deleteTree(node *root);
