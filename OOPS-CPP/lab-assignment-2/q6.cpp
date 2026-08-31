#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex() {
        real = 0;
        imaginary = 0;
    }

    Complex(double r, double i) {
        real = r;
        imaginary = i;
    }

    void display() {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

int main() {
    Complex c1;
    Complex c2(3.5, 2.5);

    cout << "Default complex number: ";
    c1.display();

    cout << "Parameterized complex number: ";
    c2.display();

    return 0;
}
