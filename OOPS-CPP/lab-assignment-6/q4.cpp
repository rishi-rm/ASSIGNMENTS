#include<iostream>
using namespace std;

class Number{
    int value;

    public:
        Number(int number): value(number){}

        Number operator+(const Number& other){
            return Number(value+other.value);
        }

        Number operator-(const Number& other){
            return Number(value-other.value);
        }

        void display(){
            cout<<value<<endl;
        }
};

int main(){
    Number first(20);
    Number second(8);
    Number sum=first+second;
    Number difference=first-second;
    cout<<"Sum: ";
    sum.display();
    cout<<"Difference: ";
    difference.display();
}
