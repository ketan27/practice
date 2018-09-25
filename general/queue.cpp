#include <iostream>
#include <queue>

using namespace std;

void display(queue <int> q)
{
    queue <int> tmp = q;

    cout << "The queue is:\n";

    while(!tmp.empty()) {
        cout << tmp.front() << "\t";
        tmp.pop();
    }

    cout << endl;
}

int main()
{
    queue<int> head;
    head.push(1);
    head.push(2);
    head.push(3);
    head.push(4);
    head.push(5);

    cout << "The queue size is " << head.size() << endl;
    cout << "First element in queue is " << head.front() << endl;
    cout << "The last element in queue is " << head.back() << endl;

    display(head);

    return 0;
}
