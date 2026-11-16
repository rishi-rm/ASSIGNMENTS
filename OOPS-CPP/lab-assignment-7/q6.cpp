#include<iostream>
using namespace std;

class Person{
    public:
        virtual ~Person(){
            cout<<"Person destructor called after Student destructor."<<endl;
        }
};

class Student: public Person{
    public:
        ~Student(){
            cout<<"Student destructor called first."<<endl;
        }
};

int main(){
    Person* person=new Student;
    delete person;
    cout<<"The derived destructor runs before the base destructor."<<endl;
}
