#include<iostream>
using namespace std;

class Vehicle{
    public:
        virtual void displayInfo() const{
            cout<<"Vehicle details"<<endl;
        }

        virtual ~Vehicle(){}
};

class Car: public Vehicle{
    public:
        void displayInfo() const override{
            cout<<"Car: 4 wheels, suitable for passenger travel"<<endl;
        }
};

class Bike: public Vehicle{
    public:
        void displayInfo() const override{
            cout<<"Bike: 2 wheels, suitable for individual travel"<<endl;
        }
};

class Bus: public Vehicle{
    public:
        void displayInfo() const override{
            cout<<"Bus: large vehicle for public transport"<<endl;
        }
};

int main(){
    Car car;
    Bike bike;
    Bus bus;
    Vehicle* vehicle=&car;
    vehicle->displayInfo();
    vehicle=&bike;
    vehicle->displayInfo();
    vehicle=&bus;
    vehicle->displayInfo();
}
