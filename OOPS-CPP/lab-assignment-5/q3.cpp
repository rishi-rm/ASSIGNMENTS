#include<iostream>
using namespace std;
class Sum{
    public:
        static int sum(int a, int b){
            return a+b;
        }
        static int sum(int a, int b, int c){
            return a+b+c;
        }
        static double sum(double a, double b){
            return a+b;
        }
};
int main(){
    cout<<"sum of two int: "<<Sum::sum(5, 8)<<endl;
    cout<<"sum of three int: "<<Sum::sum(5, 8, 14)<<endl;
    cout<<"sum of two decimals: "<<Sum::sum(5.9, 8.2)<<endl;
}