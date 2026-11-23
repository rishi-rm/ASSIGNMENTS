
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cout<<"Enter number of processes: ";
    cin>>n;
    cout<<"Enter number of resources: ";
    cin>>m;

    vector<vector<int>> Allocation(n, vector<int>(m));
    vector<vector<int>> Max(n, vector<int>(m));
    vector<vector<int>> Need(n, vector<int>(m));
    vector<int> Available(m);
    vector<int> Work(m);
    vector<bool> Finish(n, false);

    cout << "\nEnter Allocation Matrix:\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>Allocation[i][j];
        }
    }

    cout << "\nEnter Max Matrix:"<<endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>Max[i][j];
        }
    }

    cout << "\nEnter Available Resources:"<<endl;
    for (int j = 0; j < m; j++) {
        cin >> Available[j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Need[i][j]=Max[i][j]-Allocation[i][j];
        }
    }

    Work = Available;
    vector<int> SafeSequence;

    int count = 0;
    while (count < n) {
        bool found = false;
        for (int i=0; i<n; i++) {
            if (Finish[i]==false) {
                bool canExecute = true;
                for (int j= 0; j <m; j++) {
                    if (Need[i][j]>Work[j]) {
                        canExecute = false;
                        break;
                    }
                }
                if (canExecute) {
                    for (int j=0; j<m; j++) {
                        Work[j] += Allocation[i][j];
                    }

                    Finish[i] = true;
                    SafeSequence.push_back(i);
                    count++;
                    found = true;
                }
            }
        }

        if (found == false) {
            cout << "\nSystem is NOT in a safe state.\n";
            return 0;
        }
    }

    cout <<"\nSystem is in a SAFE state."<<endl;

    cout << "Safe Sequence: ";
    for (int i = 0; i < n; i++) {
        cout <<"P"<<SafeSequence[i];
        if (i != n - 1) cout << " -> ";
    }
    cout<<endl;
    return 0;
}