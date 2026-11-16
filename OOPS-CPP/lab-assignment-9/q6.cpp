#include<iostream>
#include<stdexcept>
using namespace std;

template<typename T, int SIZE>
class Stack{
    T elements[SIZE];
    int top;

    public:
        Stack(): top(-1){}

        void push(const T& value){
            if(top==SIZE-1){
                throw overflow_error("Stack overflow.");
            }
            elements[++top]=value;
        }

        T pop(){
            if(top==-1){
                throw underflow_error("Stack underflow.");
            }
            return elements[top--];
        }

        void display() const{
            if(top==-1){
                cout<<"Stack is empty."<<endl;
                return;
            }
            for(int i=top; i>=0; i--){
                cout<<elements[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    Stack<int, 3> stack;
    try{
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.display();
        stack.push(40);
    }catch(const overflow_error& error){
        cout<<"Error: "<<error.what()<<endl;
    }

    while(true){
        try{
            cout<<"Popped: "<<stack.pop()<<endl;
        }catch(const underflow_error& error){
            cout<<"Error: "<<error.what()<<endl;
            break;
        }
    }
}
