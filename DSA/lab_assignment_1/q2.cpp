#include <iostream>
using namespace std;

int main() {
    int a[] = {45, 67, 42, 67, 89, 42, 91, 10};
    int n = sizeof(a)/sizeof(a[0]);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                for (int k = j; k < n - 1; k++)
                    a[k] = a[k + 1];
                n--;
                j--;
            }
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}