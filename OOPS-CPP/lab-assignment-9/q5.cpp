#include<iostream>
#include<string>
using namespace std;

template<typename T1, typename T2>
class Pair{
    T1 first;
    T2 second;

    public:
        Pair(T1 firstValue, T2 secondValue): first(firstValue), second(secondValue){}

        void display() const{
            cout<<"First value: "<<first<<endl;
            cout<<"Second value: "<<second<<endl;
        }
};

int main(){
    Pair<int, string> pair(1, "Hello");
    pair.display();
}
