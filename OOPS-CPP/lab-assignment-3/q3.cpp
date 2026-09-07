#include<iostream>
using namespace std;

class Employee{
	private:
	int salary;

	public:
	Employee(int s){
		salary = s;
	}

	friend void compare_salary(Employee e1, Employee e2);

};

void compare_salary(Employee e1, Employee e2){
	if(e1.salary > e2.salary){
		cout<<e1.salary<<endl;
	}
	else{
		cout<<e2.salary<<endl;
	}
}

int main(){
	Employee e1(50000);
	Employee e2(60000);
	compare_salary(e1, e2);
	return 0;
}
