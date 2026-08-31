#include <iostream>
using namespace std;

class Demo {
public:
    Demo() {
        cout << "Constructor called" << endl;
    }

    ~Demo() {
        cout << "Destructor called" << endl;
    }
};

void func() {
    Demo d;
    cout << "Inside function" << endl;
}

int main() {
    Demo d1;
    cout << "Inside main before function call" << endl;
    func();
    cout << "Inside main after function call" << endl;
    return 0;
}
