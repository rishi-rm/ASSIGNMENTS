#include <iostream>
using namespace std;

class Box {
private:
    int length;
    int width;
    int height;

public:
    Box() {
        length = 1;
        width = 1;
        height = 1;
    }

    Box(int l, int w, int h) {
        length = l;
        width = w;
        height = h;
    }

    void displayVolume() {
        cout << "Volume: " << length * width * height << endl;
    }
};

int main() {
    Box b1;
    Box b2(2, 3, 4);

    cout << "Default Box Volume: ";
    b1.displayVolume();

    cout << "Parameterized Box Volume: ";
    b2.displayVolume();

    return 0;
}
