#include <iostream>
using namespace std;

class Example {
private:
    void privateFunction1() {
        cout << "This is private function 1" << endl;
    }

    void privateFunction2() {
        cout << "This is private function 2" << endl;
    }

public:
    void publicFunction() {
        cout << "Calling private function from public function" << endl;
        privateFunction1();
        privateFunction2();
    }
};

int main() {
    Example obj;
    obj.publicFunction();
    return 0;
}
