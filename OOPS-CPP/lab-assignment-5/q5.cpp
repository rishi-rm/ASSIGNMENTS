#include<iostream>
using namespace std;

class Maximum{
    public:
        static int findMax(int a, int b){
            return a>b ? a : b;
        }

        static int findMax(int a, int b, int c){
            return findMax(findMax(a, b), c);
        }

        static double findMax(double a, double b){
            return a>b ? a : b;
        }
};

int main(){
    cout<<"maximum of two integers: "<<Maximum::findMax(5, 8)<<endl;
    cout<<"maximum of three integers: "<<Maximum::findMax(5, 8, 14)<<endl;
    cout<<"maximum of two decimals: "<<Maximum::findMax(5.9, 8.2)<<endl;
}
