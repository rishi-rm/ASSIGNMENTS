#include<iostream>
using namespace std;

class Student{
    float CGPA;

    public:
        Student(float cgpa): CGPA(cgpa){}

        bool operator==(const Student& other){
            return CGPA==other.CGPA;
        }

        bool operator>(const Student& other){
            return CGPA>other.CGPA;
        }
};

int main(){
    Student first(8.5);
    Student second(9.0);

    if(first==second){
        cout<<"Both students have the same CGPA."<<endl;
    }else if(first>second){
        cout<<"The first student has the higher CGPA."<<endl;
    }else{
        cout<<"The second student has the higher CGPA."<<endl;
    }
}
