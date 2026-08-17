#include <iostream>
using namespace std;

int main() {
    int i;
    for (int j = 1; j <= 3; j++) {
        cout << j << " ";
    }
    cout << endl;

    i = 1;
    for (; i <= 3; i++) {
        cout << i << " ";
    }
    cout << endl;

    for (int j = 1; j <= 3;) {
        cout << j << " ";
        j++;
    }
    cout << endl;

    i = 1;
    for (; i <= 3;) {
        cout << i << " ";
        i++;
    }
    cout << endl;

    i = 1;
    while (i <= 4) {
        cout << i << " ";
        i++;
    }
    cout << endl;

    i = 1;
    do {
        cout << i << " ";
        i++;
    } while (i <= 4);
    cout << endl;

    return 0;
}
