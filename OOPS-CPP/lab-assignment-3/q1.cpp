#include<iostream>
using namespace std;
class Student{
    private:
    string name;
    int rno;

    public:
    Student(string n, int r){
        name = n;
        rno = r;
    }

    friend void display(Student s);

};

void display(Student s){
    cout<<s.name<<" "<<s.rno<<endl;
}

int main(){
    Student s1("Rishabh", 10091);    
    display(s1);
    return 0;
}