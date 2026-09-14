#include <iostream>
using namespace std;

class College {
protected:
    string collegeName;

public:
    College(string name) {
        collegeName = name;
        cout << "College constructor called" << endl;
    }
};

class Department : public College {
private:
    string departmentName;

public:
    Department(string college, string department) : College(college) {
        departmentName = department;
        cout << "Department constructor called" << endl;
    }

    void display() {
        cout << "\nCollege Name: " << collegeName << endl;
        cout << "Department Name: " << departmentName << endl;
    }
};

int main() {
    Department department("ABC College", "Computer Science");
    department.display();
    return 0;
}