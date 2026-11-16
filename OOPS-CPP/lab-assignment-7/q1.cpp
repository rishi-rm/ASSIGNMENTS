#include<iostream>
using namespace std;

class Month{
    public:
        virtual void show(){
            cout<<"Current month is October"<<endl;
        }
};

class NextMonth: public Month{
    public:
        void show() override{
            cout<<"Next month will be November"<<endl;
        }
};

int main(){
    Month current;
    NextMonth next;
    current.show();
    next.show();
}
