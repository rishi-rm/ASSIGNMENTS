#include<iostream>
using namespace std;
#define PI 3.14159
class Area{
    public:
        static double area(double l, double b){
            return l*b;
        }
        
        static int area(int side){
            return side*side;
        }

        static double area(double radius){
            return PI*radius*radius;
        }
};
int main(){
    cout<<"rect: "<<Area::area(7.0, 4.6)<<endl;
    cout<<"square: "<<Area::area(10)<<endl;
    cout<<"circle: "<<Area::area(11.0)<<endl;
}