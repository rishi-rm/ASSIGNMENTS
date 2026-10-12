#include<iostream>
using namespace std;

class Result{
    public:
        static void result(int marks){
            cout<<"marks in one subject: "<<marks<<endl;
        }

        static double result(double marks1, double marks2){
            return (marks1+marks2)/2;
        }

        static double result(double marks1, double marks2, double marks3){
            return (marks1+marks2+marks3)/3;
        }
};

int main(){
    Result::result(85);
    cout<<"average of two subjects: "<<Result::result(85.0, 90.0)<<endl;
    cout<<"average of three subjects: "<<Result::result(85.0, 90.0, 95.0)<<endl;
}