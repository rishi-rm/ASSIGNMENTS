#include <iostream>
using namespace std;

struct Student {
    string Name;
    int RollNo;
    string Degree;
    string Hostel;
    float CurrentCGPA;

    void addDetails() {
        cout << "Enter student name: ";
        cin >> Name;
        cout << "Enter roll number: ";
        cin >> RollNo;
        cout << "Enter degree: ";
        cin >> Degree;
        cout << "Enter hostel: ";
        cin >> Hostel;
        cout << "Enter current CGPA: ";
        cin >> CurrentCGPA;
    }

    void updateDetails() {
        cout << "Enter new name: ";
        cin >> Name;
        cout << "Enter new roll number: ";
        cin >> RollNo;
        cout << "Enter new degree: ";
        cin >> Degree;
    }

    void updateCGPA() {
        cout << "Enter updated CGPA: ";
        cin >> CurrentCGPA;
    }

    void updateHostel() {
        cout << "Enter new hostel: ";
        cin >> Hostel;
    }

    void displaydetails() {
        cout << "Name: " << Name << endl;
        cout << "Roll No: " << RollNo << endl;
        cout << "Degree: " << Degree << endl;
        cout << "Hostel: " << Hostel << endl;
        cout << "Current CGPA: " << CurrentCGPA << endl;
    }
};

int main() {
    Student s;

    s.addDetails();
    cout << "\nStudent details after adding:" << endl;
    s.displaydetails();

    s.updateCGPA();
    s.updateHostel();
    cout << "\nStudent details after updates:" << endl;
    s.displaydetails();

    return 0;
}
