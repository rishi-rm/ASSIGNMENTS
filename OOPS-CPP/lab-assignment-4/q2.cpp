#include <iostream>
using namespace std;

class Person {
protected:
    string name;
};

class Employee : public Person {
protected:
    int employeeId;
};

class Manager : public Employee {
private:
    string department;

public:
    void accept() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter employee ID: ";
        cin >> employeeId;
        cout << "Enter department: ";
        cin >> department;
    }

    void display() {
        cout << "\nManager Details\n";
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << employeeId << endl;
        cout << "Department: " << department << endl;
    }
};

int main() {
    Manager manager;
    manager.accept();
    manager.display();
    return 0;
}