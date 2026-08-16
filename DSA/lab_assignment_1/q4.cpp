#include <iostream>
using namespace std;

int main() {
    int a[] = {10, 20, 30, 40, 50};
    int n = 5;

    cout << "Reversed Array: ";
    for (int i = n - 1; i >= 0; i--)
        cout << a[i] << " ";
    cout << endl;

    int m1[2][2] = {{1, 2}, {3, 4}};
    int m2[2][2] = {{5, 6}, {7, 8}};
    int result[2][2] = {};

    cout << "Matrix Multiplication:" << endl;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++)
                result[i][j] += m1[i][k] * m2[k][j];

            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};

    cout << "Transpose of Matrix:" << endl;

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 2; i++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}