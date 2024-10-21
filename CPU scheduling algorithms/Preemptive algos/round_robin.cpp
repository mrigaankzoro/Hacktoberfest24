#include <iostream>
using namespace std;

int main()
{
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], burst[n], burstc[n], wt[n], tat[n], completed[n];
    int time = 0, count = 0;
    float sum1 = 0, sum2 = 0;

    cout << "Enter the time quantum: ";
    cin >> tq;

    // Input arrival time and burst time for each process
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> at[i];
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> burst[i];
        burstc[i] = burst[i];
        completed[i] = 0; // Mark all processes as incomplete initially
    }

    // Round-robin scheduling
    while (count < n)
    {
        bool executed = false;
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && completed[i] == 0)
            {
                if (burstc[i] > tq)
                {
                    burstc[i] -= tq; // Decrease remaining burst time
                    time += tq;      // Increase time by time quantum
                }
                else
                {
                    time += burstc[i]; // Complete the process
                    burstc[i] = 0;
                    completed[i] = 1;  // Mark process as completed
                    count++;           // Increase completed count
                    tat[i] = time - at[i]; // Calculate turnaround time
                    wt[i] = tat[i] - burst[i]; // Calculate waiting time
                    sum1 += wt[i];
                    sum2 += tat[i];
                }
                executed = true;
            }
        }
        if (!executed)
        {
            time++; // Increment time if no process was executed in this round
        }
    }

    // Output waiting time and turnaround time for each process
    for (int i = 0; i < n; i++)
    {
        cout << "Wait time for process " << i + 1 << " is " << wt[i] << endl;
        cout << "Turnaround time for process " << i + 1 << " is " << tat[i] << endl;
    }

    // Output the average waiting time and turnaround time
    cout << "\nAverage Waiting Time: " << sum1 / n << endl;
    cout << "Average Turnaround Time: " << sum2 / n << endl;

    return 0;
}
