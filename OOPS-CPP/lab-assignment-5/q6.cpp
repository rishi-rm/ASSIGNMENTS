#include<iostream>
using namespace std;

class Bill{
    public:
        static double calculateBill(int quantity, double unitPrice){
            return quantity*unitPrice;
        }

        static double calculateBill(int quantity1, double price1, int quantity2, double price2){
            return calculateBill(quantity1, price1)+calculateBill(quantity2, price2);
        }

        static double calculateBill(double billAmount, double discountPercentage){
            return billAmount-(billAmount*discountPercentage/100);
        }
};

int main(){
    cout<<"bill for one item: "<<Bill::calculateBill(3, 25.50)<<endl;
    cout<<"bill for two items: "<<Bill::calculateBill(2, 25.50, 3, 10.00)<<endl;
    cout<<"bill after discount: "<<Bill::calculateBill(100.00, 10.0)<<endl;
}
