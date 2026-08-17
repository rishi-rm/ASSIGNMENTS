#include <iostream>
using namespace std;

namespace first {
    int value = 10;
    void display() {
        cout << "Inside first namespace: value = " << value << endl;
    }
}

namespace second {
    int value = 20;
    void display() {
        cout << "Inside second namespace: value = " << value << endl;
    }
}

int main() {
    cout << "Using scope resolution operator" << endl;
    cout << "first::value = " << first::value << endl;
    cout << "second::value = " << second::value << endl;

    first::display();
    second::display();

    return 0;
}
