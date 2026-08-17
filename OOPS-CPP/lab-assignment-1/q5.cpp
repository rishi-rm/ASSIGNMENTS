#include <iostream>
using namespace std;

class AccessDemo {
private:
    int secret;

public:
    int visible;

    void setSecret(int value) {
        secret = value;
    }

    int getSecret() {
        return secret;
    }
};

class Student {
private:
    string Name;
    int RollNo;
    string Degree;
    string Hostel;
    float CurrentCGPA;

    void validateCGPA() {
        if (CurrentCGPA < 0.0) {
            CurrentCGPA = 0.0;
        }
    }

    void updateRoll() {
        RollNo = RollNo + 1;
    }

public:
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
    }

    void updateCGPA() {
        cout << "Enter updated CGPA: ";
        cin >> CurrentCGPA;
        validateCGPA();
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
    AccessDemo a;
    a.visible = 25;
    cout << "Public member value: " << a.visible << endl;
    a.setSecret(50);
    cout << "Private member accessed using public function: " << a.getSecret() << endl;

    cout << "Private data is not directly accessible from main." << endl;

    Student s;
    s.addDetails();
    s.updateCGPA();
    s.updateHostel();
    s.displaydetails();

    return 0;
}
