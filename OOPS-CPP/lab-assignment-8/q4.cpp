#include<iostream>
#include<stdexcept>
using namespace std;

int main(){
    int numbers[]={10, 20, 30, 40, 50};
    int index;
    cout<<"Enter an array index (0-4): ";
    cin>>index;

    try{
        if(index<0 || index>=5){
            throw out_of_range("Array index is outside the valid range.");
        }
        cout<<"Element: "<<numbers[index]<<endl;
    }catch(const out_of_range& error){
        cout<<"Error: "<<error.what()<<endl;
    }
}
