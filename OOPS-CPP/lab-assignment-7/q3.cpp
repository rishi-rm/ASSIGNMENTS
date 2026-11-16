#include<iostream>
using namespace std;

class Shape{
    public:
        virtual void area() const{
            cout<<"Area is not defined"<<endl;
        }

        virtual ~Shape(){}
};

class Rectangle: public Shape{
    double length;
    double width;

    public:
        Rectangle(double lengthValue, double widthValue): length(lengthValue), width(widthValue){}

        void area() const override{
            cout<<"Rectangle area: "<<length*width<<endl;
        }
};

class Circle: public Shape{
    double radius;

    public:
        Circle(double radiusValue): radius(radiusValue){}

        void area() const override{
            cout<<"Circle area: "<<3.14159*radius*radius<<endl;
        }
};

int main(){
    Rectangle rectangle(5, 3);
    Circle circle(4);
    Shape* shape=&rectangle;
    shape->area();
    shape=&circle;
    shape->area();
}
