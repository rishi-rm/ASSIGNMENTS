#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int imaginary;

public:
    void set() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imaginary;
    }

    void display() {
        cout << real << "+" << imaginary << "i" << endl;
    }

    Complex sum(Complex c) {
        Complex result;
        result.real = real + c.real;
        result.imaginary = imaginary + c.imaginary;
        return result;
    }
};

int main() {
    Complex c1, c2, c3;

    cout << "Enter first complex number" << endl;
    c1.set();
    cout << "Enter second complex number" << endl;
    c2.set();

    c3 = c1.sum(c2);

    cout << "First complex number: ";
    c1.display();
    cout << "Second complex number: ";
    c2.display();
    cout << "Sum: ";
    c3.display();

    return 0;
}
