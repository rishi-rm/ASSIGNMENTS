#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = 6, k = 2;

    k = k % n;

    for (int r = 0; r < k; r++) {
        int temp = a[n - 1];

        for (int i = n - 1; i > 0; i--)
            a[i] = a[i - 1];

        a[0] = temp;
    }

    cout << "Array after rotation: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}