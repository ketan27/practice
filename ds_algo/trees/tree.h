#include <iostream>
#include <queue>

#define LINE "-----------------------------------------------------"

using namespace std;

typedef struct _node {
    int data;
    struct _node *left;
    struct _node *right;
}node;

class tree {
    public:
        tree() {
            root = NULL;
        }
        int     insert(int val);
        int     deleteTree();
        void    display(int dispOpt = 1);
        int     find(int val);

    private:
        node*   root;
        node*   createNode(int val);
        int     deleteNode(node *elem);
        void    inorder(node *root);
        void    preorder(node *root);
        void    postorder(node *root);
};
