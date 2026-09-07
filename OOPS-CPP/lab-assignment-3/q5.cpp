#include<iostream>
using namespace std;
class BankAccount{
    private:
    int acc_no;
    double balance;

    static int total_accounts;

    public:
    BankAccount(int n, double r){
        acc_no = n;
        balance = r;
        total_accounts++;
    }

    static int get_total_accounts(){
        return total_accounts;
    }

    friend void display(BankAccount b);

};

int BankAccount::total_accounts=0;
void display(BankAccount b){
    cout<<b.acc_no<<" "<<b.balance<<endl;
}

int main(){
    BankAccount b1(10001, 54900.67);
    BankAccount b2(10002, 70000);
    BankAccount b3(10003, 45090);

    display(b1);
    display(b2);
    display(b3);

    cout<<BankAccount::get_total_accounts();
    return 0;
}