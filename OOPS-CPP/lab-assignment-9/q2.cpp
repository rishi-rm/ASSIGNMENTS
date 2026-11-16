#include<iostream>
using namespace std;

template<typename T>
void swapValues(T& first, T& second){
    T temporary=first;
    first=second;
    second=temporary;
}

int main(){
    int firstNumber=10;
    int secondNumber=20;
    swapValues(firstNumber, secondNumber);
    cout<<"Integers after swap: "<<firstNumber<<" "<<secondNumber<<endl;

    char firstCharacter='A';
    char secondCharacter='B';
    swapValues(firstCharacter, secondCharacter);
    cout<<"Characters after swap: "<<firstCharacter<<" "<<secondCharacter<<endl;
}
