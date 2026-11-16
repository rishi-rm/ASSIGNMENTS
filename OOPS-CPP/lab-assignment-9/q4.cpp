#include<iostream>
using namespace std;

template<typename T, int SIZE>
class ArrayOperations{
    T elements[SIZE];

    public:
        ArrayOperations(const T (&values)[SIZE]){
            for(int i=0; i<SIZE; i++){
                elements[i]=values[i];
            }
        }

        void display() const{
            for(int i=0; i<SIZE; i++){
                cout<<elements[i]<<" ";
            }
            cout<<endl;
        }

        T largest() const{
            T maximum=elements[0];
            for(int i=1; i<SIZE; i++){
                if(elements[i]>maximum){
                    maximum=elements[i];
                }
            }
            return maximum;
        }
};

int main(){
    int values[]={12, 45, 7, 32, 19};
    ArrayOperations<int, 5> array(values);
    cout<<"Array elements: ";
    array.display();
    cout<<"Largest element: "<<array.largest()<<endl;
}
