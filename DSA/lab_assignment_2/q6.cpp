#include <iostream>
using namespace std;

struct Element {
    int row;
    int col;
    int value;
};

struct SparseMatrix {
    int rows;
    int cols;
    int terms;
    Element data[100];
};

void display(SparseMatrix matrix) {
    int k = 0;

    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            if (k < matrix.terms &&
                matrix.data[k].row == i &&
                matrix.data[k].col == j) {
                cout << matrix.data[k].value << " ";
                k++;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

SparseMatrix transpose(SparseMatrix matrix) {
    SparseMatrix result;

    result.rows = matrix.cols;
    result.cols = matrix.rows;
    result.terms = matrix.terms;

    int k = 0;

    for (int col = 0; col < matrix.cols; col++) {
        for (int i = 0; i < matrix.terms; i++) {
            if (matrix.data[i].col == col) {
                result.data[k].row = matrix.data[i].col;
                result.data[k].col = matrix.data[i].row;
                result.data[k].value = matrix.data[i].value;
                k++;
            }
        }
    }

    return result;
}

SparseMatrix add(SparseMatrix a, SparseMatrix b) {
    SparseMatrix result;

    result.rows = a.rows;
    result.cols = a.cols;
    result.terms = 0;

    int i = 0;
    int j = 0;

    while (i < a.terms && j < b.terms) {
        if (a.data[i].row < b.data[j].row ||
            (a.data[i].row == b.data[j].row &&
             a.data[i].col < b.data[j].col)) {

            result.data[result.terms++] = a.data[i++];
        }
        else if (b.data[j].row < a.data[i].row ||
                 (a.data[i].row == b.data[j].row &&
                  b.data[j].col < a.data[i].col)) {

            result.data[result.terms++] = b.data[j++];
        }
        else {
            int value = a.data[i].value + b.data[j].value;

            if (value != 0) {
                result.data[result.terms].row = a.data[i].row;
                result.data[result.terms].col = a.data[i].col;
                result.data[result.terms].value = value;
                result.terms++;
            }

            i++;
            j++;
        }
    }

    while (i < a.terms)
        result.data[result.terms++] = a.data[i++];

    while (j < b.terms)
        result.data[result.terms++] = b.data[j++];

    return result;
}

SparseMatrix multiply(SparseMatrix a, SparseMatrix b) {
    SparseMatrix result;

    result.rows = a.rows;
    result.cols = b.cols;
    result.terms = 0;

    int denseA[20][20] = {};
    int denseB[20][20] = {};
    int denseC[20][20] = {};

    for (int i = 0; i < a.terms; i++)
        denseA[a.data[i].row][a.data[i].col] = a.data[i].value;

    for (int i = 0; i < b.terms; i++)
        denseB[b.data[i].row][b.data[i].col] = b.data[i].value;

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            for (int k = 0; k < a.cols; k++) {
                denseC[i][j] += denseA[i][k] * denseB[k][j];
            }
        }
    }

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            if (denseC[i][j] != 0) {
                result.data[result.terms].row = i;
                result.data[result.terms].col = j;
                result.data[result.terms].value = denseC[i][j];
                result.terms++;
            }
        }
    }

    return result;
}

int main() {
    SparseMatrix A;

    A.rows = 3;
    A.cols = 3;
    A.terms = 4;

    A.data[0] = {0, 0, 1};
    A.data[1] = {0, 2, 2};
    A.data[2] = {1, 1, 3};
    A.data[3] = {2, 0, 4};

    cout << "Original Matrix:" << endl;
    display(A);

    SparseMatrix T = transpose(A);

    cout << "\nTranspose:" << endl;
    display(T);

    SparseMatrix B;

    B.rows = 3;
    B.cols = 3;
    B.terms = 4;

    B.data[0] = {0, 0, 5};
    B.data[1] = {0, 1, 6};
    B.data[2] = {1, 1, 7};
    B.data[3] = {2, 2, 8};

    SparseMatrix sum = add(A, B);

    cout << "\nAddition:" << endl;
    display(sum);

    SparseMatrix product = multiply(A, B);

    cout << "\nMultiplication:" << endl;
    display(product);

    return 0;
}