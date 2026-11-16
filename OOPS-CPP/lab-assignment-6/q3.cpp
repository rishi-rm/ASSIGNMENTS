#include<iostream>
using namespace std;

class Number{
    int value;

    public:
        Number(int number): value(number){}

        Number operator+(const Number& other){
            return Number(value+other.value);
        }

        void display(){
            cout<<value<<endl;
        }
};

int main(){
    Number first(10);
    Number second(20);
    Number result=first+second;
    cout<<"Sum: ";
    result.display();
}
