#include <iostream>
using namespace std;

class Academic {
protected:
    int marks;
};

class Sports {
protected:
    int sportsScore;
};

class Result : public Academic, public Sports {
public:
    void accept() {
        cout << "Enter academic marks: ";
        cin >> marks;
        cout << "Enter sports score: ";
        cin >> sportsScore;
    }

    void display() {
        cout << "\nResult\n";
        cout << "Academic Marks: " << marks << endl;
        cout << "Sports Score: " << sportsScore << endl;
        cout << "Total Score: " << marks + sportsScore << endl;
    }
};

int main() {
    Result result;
    result.accept();
    result.display();
    return 0;
}