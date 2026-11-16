#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> numbers={10, 20, 30, 40, 50};
    int sum=0;

    cout<<"Vector elements: ";
    for(int number : numbers){
        cout<<number<<" ";
        sum+=number;
    }

    cout<<endl<<"Sum: "<<sum<<endl;
}
