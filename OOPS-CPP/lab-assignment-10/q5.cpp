#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<int, string> students;
    int count;
    cout<<"Enter the number of student records: ";
    cin>>count;

    for(int i=0; i<count; i++){
        int rollNumber;
        string name;
        cout<<"Enter roll number and name: ";
        cin>>rollNumber>>name;
        students[rollNumber]=name;
    }

    int searchRollNumber;
    cout<<"Enter a roll number to search: ";
    cin>>searchRollNumber;
    auto student=students.find(searchRollNumber);
    if(student!=students.end()){
        cout<<"Student: "<<student->second<<endl;
    }else{
        cout<<"No student found with roll number "<<searchRollNumber<<"."<<endl;
    }

    cout<<"All student records:"<<endl;
    for(const auto& record : students){
        cout<<record.first<<" "<<record.second<<endl;
    }
}
