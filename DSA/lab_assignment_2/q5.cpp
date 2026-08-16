#include <iostream>
using namespace std;

int main() {
    int n = 4;

    int diagonal[] = {1, 2, 3, 4};

    cout << "Diagonal Matrix Storage:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << diagonal[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    int tridiagonal[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "\nTri-diagonal Matrix Storage:" << endl;

    int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(i - j) <= 1)
                cout << tridiagonal[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    int lower[] = {
        1,
        2, 3,
        4, 5, 6,
        7, 8, 9, 10
    };

    cout << "\nLower Triangular Matrix Storage:" << endl;

    k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j)
                cout << lower[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    int upper[] = {
        1, 2, 3, 4,
        5, 6, 7,
        8, 9,
        10
    };

    cout << "\nUpper Triangular Matrix Storage:" << endl;

    k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j)
                cout << upper[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    int symmetric[] = {
        1, 2, 3, 4,
        5, 6, 7,
        8, 9,
        10
    };

    cout << "\nSymmetric Matrix Storage:" << endl;

    k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                int index = i * (i + 1) / 2 + j;
                cout << symmetric[index] << " ";
            } else {
                int index = j * (j + 1) / 2 + i;
                cout << symmetric[index] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}