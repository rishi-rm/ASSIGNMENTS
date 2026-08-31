#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    float cgpa;

public:
    Student() {
        name = "Unknown";
        rollNo = 0;
        cgpa = 0.0;
    }

    Student(string n, int r) {
        name = n;
        rollNo = r;
        cgpa = 0.0;
    }

    Student(string n, int r, float c) {
        name = n;
        rollNo = r;
        cgpa = c;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

int main() {
    Student s1;
    Student s2("Bob", 12);
    Student s3("Charlie", 13, 8.7f);

    cout << "Student 1" << endl;
    s1.display();

    cout << "Student 2" << endl;
    s2.display();

    cout << "Student 3" << endl;
    s3.display();

    return 0;
}
