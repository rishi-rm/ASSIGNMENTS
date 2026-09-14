#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
};

class Student : public Person {
private:
    int rollNumber;
    string course;

public:
    void accept() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cout << "Enter course: ";
        cin >> course;
    }

    void display() {
        cout << "\nStudent Details\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Course: " << course << endl;
    }
};

int main() {
    Student student;
    student.accept();
    student.display();
    return 0;
}