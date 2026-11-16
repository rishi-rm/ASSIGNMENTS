#include<iostream>
using namespace std;

class Animal{
    public:
        virtual void sound(){
            cout<<"Animal sound"<<endl;
        }

        virtual ~Animal(){}
};

class Dog: public Animal{
    public:
        void sound() override{
            cout<<"Dog says: Woof!"<<endl;
        }
};

class Cat: public Animal{
    public:
        void sound() override{
            cout<<"Cat says: Meow!"<<endl;
        }
};

int main(){
    Dog dog;
    Cat cat;
    Animal* animal=&dog;
    animal->sound();
    animal=&cat;
    animal->sound();
}
