#include<iostream>
using namespace std;

template<typename T>
T maximum(T first, T second){
    return first>second ? first : second;
}

int main(){
    cout<<"Maximum integer: "<<maximum(10, 25)<<endl;
    cout<<"Maximum floating-point number: "<<maximum(4.5, 2.8)<<endl;
}
