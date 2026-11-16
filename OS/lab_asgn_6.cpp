// FCFS

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of processes must be positive.\n";
        return 1;
    }

    vector<int> burstTime(n), waitingTime(n), turnaroundTime(n);
    cout << "Enter burst time for each process:\n";
    for (int i = 0; i < n; ++i) {
        cout << "P" << i + 1 << ": ";
        cin >> burstTime[i];
    }

    waitingTime[0] = 0;
    for (int i = 1; i < n; ++i) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }

    double totalWaitingTime = 0;
    double totalTurnaroundTime = 0;
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; ++i) {
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
        cout << "P" << i + 1 << "\t" << burstTime[i] << "\t\t"
             << waitingTime[i] << "\t\t" << turnaroundTime[i] << '\n';
    }

    cout << "\nAverage waiting time: " << totalWaitingTime / n << '\n';
    cout << "Average turnaround time: " << totalTurnaroundTime / n << '\n';
    return 0;
}