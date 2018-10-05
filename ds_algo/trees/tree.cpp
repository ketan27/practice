#include "tree.h"

using namespace std;

void tree::inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << "  ";
    inorder(root->right);
}

void tree::preorder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << "  ";
    preorder(root->left);
    preorder(root->right);
}

void tree::postorder(node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << "  ";
}

int tree::deleteNode(node *elem)
{
    if (elem == NULL) {
        return 1;
    }

    // delete the node if its a leaf
    if (elem->left == NULL && elem->right == NULL) {
        cout << "cleaning " << elem->data << endl;
        delete elem;
        return 1;
    }

    deleteNode(elem->left);
    deleteNode(elem->right);
    cout << "cleaning " << elem->data << endl;
    delete elem;

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
#ifdef DBG
        cout << "Inserted " << val << " as root" << endl;
#endif
    } else {
        // All other cases
        queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            node *tmp = q.front();
            q.pop();
#ifdef DBG
            cout << "I have popped " << tmp->data << endl;
#endif

            // Check for place in left node
            if (!tmp->left) {
                tmp->left = elem;
#ifdef DBG
                cout << "Inserted " << val << " in left node" << endl;
#endif
                break;
            } else {
                q.push(tmp->left);
            }

            // check for place in right node
            if (!tmp->right) {
                tmp->right = elem;
#ifdef DBG
                cout << "Inserted " << val << " in right node" << endl;
#endif
                break;
            } else {
                q.push(tmp->right);
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
        case 0:
            cout << "Displaying in pre-order" << endl;
            cout << LINE << endl;
            preorder(root);
            cout << endl << LINE << endl << endl;
            break;
        case 1:
            cout << "Displaying in-order layout" << endl;
            cout << LINE << endl;
            inorder(root);
            cout << endl << LINE << endl << endl;
            break;
        case 2:
            cout << "Displaying in post-order" << endl;
            cout << LINE << endl;
            postorder(root);
            cout << endl << LINE << endl << endl;
            break;
        default:
            cout << "Wrong type of traversal selected" << endl;
    }
}

/*
 * 0 for not found, else 1
 */
int tree::find(int val)
{
    int isFound = 0;

    if (root == NULL) {
        return isFound;
    }

    if (root->data == val) {
        // When element is found at the root node only
        isFound = 1;
    } else {
        // now scan left and right sub-tree one by one
        queue<node *> q;
        q.push(root);

        while (!q.empty()) {
            node *iter = q.front();
            q.pop();

            // Does the left node even exists?
            if (iter->left == NULL) {
                break;
            }

            if (iter->left->data == val) {
                // when element is in the left node
                isFound = 1;
                break;
            } else {
                q.push(iter->left);
            }

            if (iter->right == NULL) {
                break;
            }
            if (iter->right->data == val) {
                // when it is in the left node
                isFound = 1;
                break;
            } else {
                q.push(iter->right);
            }
        }
    }

    return isFound;
}

/*
 * 1 for successfull deletion else 0
 */
int tree::deleteTree()
{
    int deleted = 0;

    if (root == NULL) {
        return deleted;
    }

    if (deleteNode(root)) {
        deleted = 1;
    }

    return deleted;
}

int main()
{
    tree t1;

    t1.insert(1);
    t1.insert(2);
    t1.insert(3);
    t1.insert(50);
    t1.insert(234);
    t1.insert(45);
    t1.insert(34);
    t1.insert(23);
    t1.insert(0);

    t1.display(0);
    t1.display(1);
    t1.display(2);

    if (t1.find(0)) {
        cout << "I have found \"0\" in the tree" << endl;
    } else {
        cout << "I could not find \"0\" in the tree" << endl;
    }

    if (t1.find(100)) {
        cout << "I have found \"100\" in the tree" << endl;
    } else {
        cout << "I could not find \"100\" in the tree" << endl;
    }

    if (t1.find(1)) {
        cout << "I have found \"1\" in the tree" << endl;
    } else {
        cout << "I could not find \"1\" in the tree" << endl;
    }

    if (t1.deleteTree()) {
        cout << "Successfully deleted the tree\n";
    }


    return 0;
}
