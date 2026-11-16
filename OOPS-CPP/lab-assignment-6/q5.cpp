#include<iostream>
using namespace std;

class Complex{
    int real;
    int imaginary;

    public:
        Complex(int realPart, int imaginaryPart): real(realPart), imaginary(imaginaryPart){}

        Complex operator+(const Complex& other){
            return Complex(real+other.real, imaginary+other.imaginary);
        }

        void display(){
            cout<<real<<" + "<<imaginary<<"i"<<endl;
        }
};

int main(){
    Complex first(3, 4);
    Complex second(2, 5);
    Complex result=first+second;
    cout<<"Result: ";
    result.display();
}
