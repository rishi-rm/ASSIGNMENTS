#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> numbers={42, 17, 8, 31, 25};
    sort(numbers.begin(), numbers.end());

    cout<<"Sorted elements: ";
    for(int number : numbers){
        cout<<number<<" ";
    }
    cout<<endl;

    int value;
    cout<<"Enter a value to search for: ";
    cin>>value;

    if(binary_search(numbers.begin(), numbers.end(), value)){
        cout<<value<<" was found."<<endl;
    }else{
        cout<<value<<" was not found."<<endl;
    }
}
