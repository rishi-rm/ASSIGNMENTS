#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main(){
    stack<int> numberStack;
    numberStack.push(10);
    numberStack.push(20);
    numberStack.push(30);
    cout<<"Stack top: "<<numberStack.top()<<endl;
    numberStack.pop();
    cout<<"Stack top after pop: "<<numberStack.top()<<endl;

    queue<int> numberQueue;
    numberQueue.push(10);
    numberQueue.push(20);
    numberQueue.push(30);
    cout<<"Queue front: "<<numberQueue.front()<<endl;
    numberQueue.pop();
    cout<<"Queue front after pop: "<<numberQueue.front()<<endl;
}
