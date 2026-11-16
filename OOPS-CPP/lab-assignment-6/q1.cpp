#include<iostream>
using namespace std;

class Counter{
    int count;

    public:
        Counter(int value): count(value){}

        Counter& operator++(){
            ++count;
            return *this;
        }

        void display(){
            cout<<count<<endl;
        }
};

int main(){
    Counter counter(5);
    cout<<"Before ++: ";
    counter.display();
    ++counter;
    cout<<"After ++: ";
    counter.display();
}
