#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    int total = n * (n + 1) / 2;

    int sum = 0;

    for (int i = 0; i < n - 1; i++)
        sum += arr[i];

    return total - sum;
}

int findMissingBinary(int arr[], int n) {
    int low = 0;
    int high = n - 2;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == mid + 1)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low + 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    int n = 10;

    cout << "Missing number using linear search: "
         << findMissingLinear(arr, n) << endl;

    cout << "Missing number using binary search: "
         << findMissingBinary(arr, n) << endl;

    return 0;
}