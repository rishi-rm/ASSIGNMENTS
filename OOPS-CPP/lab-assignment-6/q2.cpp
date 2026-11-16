#include<iostream>
using namespace std;

class Number{
    int value;

    public:
        Number(int number): value(number){}

        Number& operator--(){
            --value;
            return *this;
        }

        void display(){
            cout<<value<<endl;
        }
};

int main(){
    Number number(5);
    cout<<"Before --: ";
    number.display();
    --number;
    cout<<"After --: ";
    number.display();
}
