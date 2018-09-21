#include <iostream>

using namespace std;

class foo {
    int num;

    public:
    foo(): num (0) {}

    int get_num() {return num;}
    int set_num(int x) {num = x;}

    friend ostream& operator << (ostream& out, const foo& obj) {
        out << obj.num;
        return out;
    }

    friend istream& operator >> (istream& in, foo& obj) {
        in >> obj.num;
        return in;
    }

};

int main()
{
    foo f1;

    cout << f1.get_num() << endl;
    f1.set_num(5);
    cout << f1.get_num() << endl;
    cout << f1 << endl;
    cout << "Enter new no.: ";
    cin >> f1;
    cout << f1 << endl;

    return 0;
}

