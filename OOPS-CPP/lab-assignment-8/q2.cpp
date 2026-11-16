#include<iostream>
using namespace std;

int main(){
    int age;
    cout<<"Enter age: ";
    cin>>age;

    try{
        if(age<0){
            throw invalid_argument("Age cannot be negative.");
        }
        cout<<"Age: "<<age<<endl;
    }catch(const invalid_argument& error){
        cout<<"Error: "<<error.what()<<endl;
    }
}
