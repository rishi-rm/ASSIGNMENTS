#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int breadth;

public:
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }

    void displayArea() {
        cout << "Area: " << length * breadth << endl;
    }
};

int main() {
    Rectangle r(5, 4);
    r.displayArea();
    return 0;
}
