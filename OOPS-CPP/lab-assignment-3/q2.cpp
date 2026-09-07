#include<iostream>
using namespace std;
class Number{
    private:
    int a;
    int b;

    public:
    Number(int n, int r){
        a = n;
        b = r;
    }

    friend void display_sum(Number n);

};

void display_sum(Number n){
    cout<<n.a+n.b<<endl;
}

int main(){
    Number n(4, 5);
    display_sum(n);
    return 0;
}