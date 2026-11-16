#include<iostream>
using namespace std;

class Employee{
    protected:
        string name;
        double basicSalary;

    public:
        Employee(string employeeName, double salary): name(employeeName), basicSalary(salary){}

        string getName() const{
            return name;
        }

        virtual double calculateSalary() const{
            return basicSalary;
        }

        virtual ~Employee(){}
};

class PermanentEmployee: public Employee{
    public:
        PermanentEmployee(string employeeName, double salary): Employee(employeeName, salary){}

        double calculateSalary() const override{
            return basicSalary*1.2;
        }
};

class ContractEmployee: public Employee{
    double hoursWorked;

    public:
        ContractEmployee(string employeeName, double hourlyRate, double hours): Employee(employeeName, hourlyRate), hoursWorked(hours){}

        double calculateSalary() const override{
            return basicSalary*hoursWorked;
        }
};

int main(){
    PermanentEmployee permanent("Alex", 5000);
    ContractEmployee contract("Sam", 25, 160);
    Employee* employee=&permanent;
    cout<<employee->getName()<<": "<<employee->calculateSalary()<<endl;
    employee=&contract;
    cout<<employee->getName()<<": "<<employee->calculateSalary()<<endl;
}
