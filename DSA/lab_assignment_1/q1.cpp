#include <iostream>
using namespace std;

int main() {
    int arr[100];
    int n = 0;
    int choice, value, pos, i;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "==========================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter number of elements: ";
            cin >> n;

            cout << "Enter " << n << " elements:\n";
            for (i = 0; i < n; i++) {
                cin >> arr[i];
            }

            cout << "Array created successfully.\n";
            break;

        case 2:
            if (n == 0) {
                cout << "Array is empty.\n";
            } else {
                cout << "Array elements are: ";
                for (i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            break;

        case 3:
            if (n >= 100) {
                cout << "Array is full. Cannot insert.\n";
                break;
            }

            cout << "Enter position (1 to " << n + 1 << "): ";
            cin >> pos;

            if (pos < 1 || pos > n + 1) {
                cout << "Invalid position.\n";
                break;
            }

            cout << "Enter value to insert: ";
            cin >> value;

            for (i = n; i >= pos; i--) {
                arr[i] = arr[i - 1];
            }

            arr[pos - 1] = value;
            n++;

            cout << "Element inserted successfully.\n";
            break;

        case 4:
            if (n == 0) {
                cout << "Array is empty. Cannot delete.\n";
                break;
            }

            cout << "Enter position to delete (1 to " << n << "): ";
            cin >> pos;

            if (pos < 1 || pos > n) {
                cout << "Invalid position.\n";
                break;
            }

            for (i = pos - 1; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }

            n--;

            cout << "Element deleted successfully.\n";
            break;

        case 5:
            if (n == 0) {
                cout << "Array is empty.\n";
                break;
            }

            cout << "Enter element to search: ";
            cin >> value;

            for (i = 0; i < n; i++) {
                if (arr[i] == value) {
                    cout << "Element found at position " << i + 1 << ".\n";
                    break;
                }
            }

            if (i == n) {
                cout << "Element not found.\n";
            }
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}