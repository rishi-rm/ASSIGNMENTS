#include<iostream>
using namespace std;

int main(){
    double numerator;
    double denominator;
    cout<<"Enter numerator and denominator: ";
    cin>>numerator>>denominator;

    try{
        if(denominator==0){
            throw runtime_error("Cannot divide by zero.");
        }
        cout<<"Result: "<<numerator/denominator<<endl;
    }catch(const runtime_error& error){
        cout<<"Error: "<<error.what()<<endl;
    }
}
