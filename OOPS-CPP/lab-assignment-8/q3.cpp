#include<iostream>
using namespace std;

int main(){
    int number;
    cout<<"Enter an integer from 0 to 100: ";
    cin>>number;

    try{
        if(number<0){
            throw underflow_error("The number cannot be negative.");
        }
        if(number>100){
            throw overflow_error("The number cannot be greater than 100.");
        }
        cout<<"Valid number: "<<number<<endl;
    }catch(const underflow_error& error){
        cout<<"Error: "<<error.what()<<endl;
    }catch(const overflow_error& error){
        cout<<"Error: "<<error.what()<<endl;
    }
}
