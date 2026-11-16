#include<iostream>
#include<stdexcept>
using namespace std;

class LibraryAccount{
    int availableBooks;

    public:
        LibraryAccount(int books): availableBooks(books){}

        void issueBook(int bookCount){
            if(bookCount>availableBooks){
                throw runtime_error("Not enough books are available.");
            }
            availableBooks-=bookCount;
            cout<<bookCount<<" book(s) issued. Books remaining: "<<availableBooks<<endl;
        }
};

int main(){
    LibraryAccount account(5);
    int bookCount;
    cout<<"Enter number of books to issue: ";
    cin>>bookCount;

    try{
        account.issueBook(bookCount);
    }catch(const runtime_error& error){
        cout<<"Error: "<<error.what()<<endl;
    }
}
