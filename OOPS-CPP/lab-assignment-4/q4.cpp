#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;
    string model;
};

class Car : public Vehicle {
private:
    int numberOfDoors;

public:
    void accept() {
        cout << "Enter car brand: ";
        cin >> brand;
        cout << "Enter car model: ";
        cin >> model;
        cout << "Enter number of doors: ";
        cin >> numberOfDoors;
    }

    void display() {
        cout << "\nCar Details\n";
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Number of Doors: " << numberOfDoors << endl;
    }
};

class Bike : public Vehicle {
private:
    int engineCapacity;

public:
    void accept() {
        cout << "Enter bike brand: ";
        cin >> brand;
        cout << "Enter bike model: ";
        cin >> model;
        cout << "Enter engine capacity: ";
        cin >> engineCapacity;
    }

    void display() {
        cout << "\nBike Details\n";
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Engine Capacity: " << engineCapacity << " cc" << endl;
    }
};

int main() {
    Car car;
    Bike bike;
    car.accept();
    bike.accept();
    car.display();
    bike.display();
    return 0;
}