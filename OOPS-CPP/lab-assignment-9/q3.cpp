#include<iostream>
#include<stdexcept>
using namespace std;

template<typename T>
class Calculator{
    T first;
    T second;

    public:
        Calculator(T firstValue, T secondValue): first(firstValue), second(secondValue){}

        T add() const{
            return first+second;
        }

        T subtract() const{
            return first-second;
        }

        T multiply() const{
            return first*second;
        }

        T divide() const{
            if(second==T()){
                throw runtime_error("Cannot divide by zero.");
            }
            return first/second;
        }
};

int main(){
    Calculator<double> calculator(20.0, 4.0);
    cout<<"Addition: "<<calculator.add()<<endl;
    cout<<"Subtraction: "<<calculator.subtract()<<endl;
    cout<<"Multiplication: "<<calculator.multiply()<<endl;
    try{
        cout<<"Division: "<<calculator.divide()<<endl;
    }catch(const runtime_error& error){
        cout<<"Error: "<<error.what()<<endl;
    }
}
