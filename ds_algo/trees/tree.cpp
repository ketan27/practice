#include "tree.h"

using namespace std;

void tree::inorder(node *root)
{
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << "\t";
    inorder(root->right);
}

int tree::deleteNode(node *elem)
{
    return 1;
}

node* tree::createNode(int val)
{
    node *tmp = new node;

    if (tmp) {
        tmp->data = val;
        tmp->left = NULL;
        tmp->right = NULL;
    }

    return tmp;
}

// returns 0 for success and 1 for fail
int tree::insert(int val)
{
    int retVal = 0;
    node *elem = createNode(val);

    if (elem == NULL) {
        // When there is any error in allocating memory
        retVal = 1;
    } else if (root == NULL) {
        // The first insertion, which would be the root
        root = elem;
    } else {
        // All other cases
        queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            node *tmp = q.front();
            q.pop();

            // Check for place in left node
            if (!tmp->left) {
                tmp->left = elem;
                break;
            } else {
                q.push(tmp->left);
            }

            // check for place in right node
            if (!tmp->right) {
                tmp->right = elem;
                break;
            } else {
                q.push(elem);
            }
        }
    }

    return retVal;
}

/*
 * values of order -
 * 0: preorder traversal
 * 1: inorder
 * 2: postorder
 * 3: levelorder
 */
void tree::display(int dispOpt)
{
    if (!root) {
        cout << "Tree is empty" << endl;
        return;
    }

    switch(dispOpt) {
        case 1:
            cout << "Displaying in-order layout" << endl;
            inorder(root);
            break;

        default:
            cout << "Wrong type of traversal selected" << endl;
    }
}

int tree::find(int val)
{
    return 1;
}

int tree::deleteTree()
{
    return 1;
}

int main()
{
    tree t1;

    t1.insert(1);
    t1.insert(2);
    t1.insert(3);

    t1.display();
    return 0;
}
