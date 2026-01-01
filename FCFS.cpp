#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[20], ct[20], tat[20], wt[20];
    float avg_wt = 0, avg_tat = 0;

    cout << "Enter Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << ": ";
        cin >> bt[i];
    }

    // Calculate Completion Time
    ct[0] = bt[0];
    for (int i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];
    }

    // Calculate TAT and WT (AT = 0 for all)
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i];          // TAT = CT - AT  (AT=0)
        wt[i] = tat[i] - bt[i];  // WT  = TAT - BT
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    // Output
    cout << "\nProcess\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << bt[i] << "\t" << ct[i]
             << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << avg_wt / n;
    cout << "\nAverage Turnaround Time: " << avg_tat / n << "\n";

    return 0;
}
