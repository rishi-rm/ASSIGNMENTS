#include<iostream>
using namespace std;

class Print{
    public:
        void display(int x){
            cout<<x<<endl;
        }

        void display(double x){
            cout<<x<<endl;
        }

        void display(string x){
            cout<<x<<endl;
        }
};

int main(){
    Print p;
    p.display(67);
    p.display(41.5);
    p.display("Rishabh");
}