#include <algorithm>  // For sorting
#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int burstTime[n], waitingTime[n], turnaroundTime[n], completionTime[n];

    // Input burst times for each process
    for (int i = 0; i < n; i++) {
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> burstTime[i];
    }

    // Sort the burst times in ascending order (Shortest Job First)
    sort(burstTime, burstTime + n);

    // Completion time calculation (based on sorted burst times)
    completionTime[0] = burstTime[0];
    for (int i = 1; i < n; i++) {
        completionTime[i] = completionTime[i - 1] + burstTime[i];
    }

    // Calculate Turnaround Time (TAT) and Waiting Time
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = completionTime[i];              // TAT = Completion Time (since arrival time is 0)
        waitingTime[i] = turnaroundTime[i] - burstTime[i];  // Waiting Time = TAT - Burst Time
    }

    // Output results
    cout << "\nProcess\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << burstTime[i] << "\t\t" << completionTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << endl;
    }

    // Calculate and print average waiting time and turnaround time
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    cout << "\nAverage Waiting Time: " << (float)totalWaitingTime / n;
    cout << "\nAverage Turnaround Time: " << (float)totalTurnaroundTime / n << endl;

    return 0; 
}
