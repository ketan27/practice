#include <iostream>
#include <cstddef>

using namespace std;

typedef struct node {
    int data;
    struct node* next;
}node;

class lists {
private:
    node *head, *tail;

public:
    lists(): head(nullptr), tail(nullptr) {}

    int add(int num, int pos = 0);
    void print();
};

int lists::add(int num, int pos)
{
    node *tmp = new node;
    tmp->data = num;
    tmp->next = nullptr;

    if (!tmp)
        return 0;

    if (head == nullptr) {
        head = tmp;
        tail = tmp;
    } else {
        tmp->next = head;
        head = tmp;
    }

    return 1;
}

void lists::print()
{
    node *tmp = head;

    while (tmp != nullptr) {
        cout << tmp->data << "->";
        tmp = tmp->next;
    }

    cout << endl;
}


int main()
{
    lists l1;

    for (int i = 0; i < 10; ++i) {
        l1.add(i);
    }

    l1.print();

    return 0;
}











