#include<iostream>
#include<stdexcept>
using namespace std;

class Student{
    int marks[5];

    public:
        void inputMarks(){
            for(int i=0; i<5; i++){
                cout<<"Enter marks for subject "<<i+1<<": ";
                cin>>marks[i];
                if(marks[i]<0 || marks[i]>100){
                    throw out_of_range("Each mark must be between 0 and 100.");
                }
            }
        }

        double calculateAverage() const{
            int total=0;
            for(int i=0; i<5; i++){
                total+=marks[i];
            }
            return total/5.0;
        }
};

int main(){
    Student student;
    try{
        student.inputMarks();
        cout<<"Average marks: "<<student.calculateAverage()<<endl;
    }catch(const out_of_range& error){
        cout<<"Error: "<<error.what()<<endl;
    }
}
