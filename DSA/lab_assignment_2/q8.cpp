#include <iostream>
using namespace std;

int countDistinct(int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        bool alreadyExists = false;

        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                alreadyExists = true;
                break;
            }
        }

        if (!alreadyExists)
            count++;
    }

    return count;
}

int main() {
    int arr[] = {10, 20, 10, 30, 20, 40, 50, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Number of distinct elements: "
         << countDistinct(arr, n) << endl;

    return 0;
}