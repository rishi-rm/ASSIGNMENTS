#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int main(){
    list<int> numbers={20, 30};
    numbers.push_front(10);
    numbers.push_back(40);

    auto element=find(numbers.begin(), numbers.end(), 20);
    if(element!=numbers.end()){
        numbers.erase(element);
    }

    cout<<"List elements: ";
    for(int number : numbers){
        cout<<number<<" ";
    }
    cout<<endl;
}
