#include<iostream>
using namespace std;

class Student{
    int rno;
    static int obj_count;

    public: Student(int r){
        rno = r;
        obj_count++;
    }

    int get_obj_count(){
        return obj_count;
    }
};

int Student::obj_count=0;

int main(){
    Student s1(101);
    Student s2(102);
    Student s3(103);

    cout<<s1.get_obj_count();
    return 0;
}