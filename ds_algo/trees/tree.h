#include <iostream>
#include <queue>

using namespace std;

class tree {

    public:
        tree()  {   root = NULL;    }
        int     insertNode(int val);
        int     deleteTree();
        void    display(int dispOpt = 0);
        int     find(int val);

    private:
        typedef struct _node {
            int data;
            struct _node *left;
            struct _node *right
        }node;

        node*   createNode(int val);
        int     deleteNode(node *elem);
        void    inorder(node *elem);
        node    *root;
};
