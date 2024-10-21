#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], tat[n], wt[n], burst[n], burstc[n], time = 0;

    // Input arrival times and burst times
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Arrival time for process " << i + 1 << ": ";
        cin >> at[i];
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> burst[i];
        burstc[i] = burst[i]; // Backup burst time
    }

    // Shortest Job First logic
    for (int i = 0; i < n; i++)
    {
        int shortest = burst[i]; // Assume the current burst time is the shortest

        // Find the shortest job that has arrived
        for (int j = 0; j < n; j++)
        {
            if (shortest > burst[j] && burst[j] >= at[j])
            {
                shortest = burst[j];
            }
        }

        // Assign waiting time and update time for the process with the shortest burst time
        for (int k = 0; k < n; k++)
        {
            if (burst[k] == shortest)
            {
                wt[k] = time - at[k]; // Calculate waiting time
                time += shortest;     // Increment the total time
                burst[k] = 9999999;   // Mark the process as completed by setting a large burst time
                break;
            }
        }
    }

    int sum1 = 0, sum2 = 0;

    // Calculate waiting time and turnaround time for each process
    for (int i = 0; i < n; i++)
    {
        cout << "The wait time for process " << i + 1 << " is " << wt[i] << endl;
        tat[i] = wt[i] + burstc[i]; // Corrected to use burstc[i] instead of burstc[1]
        cout << "The turnaround time for process " << i + 1 << " is " << tat[i] << endl;
        sum1 += wt[i];  // Corrected to sum wt[i] instead of wt[1]
        sum2 += tat[i]; // Corrected to accumulate sum2 properly
    }

    // Calculate and print the average waiting time and turnaround time
    cout << "Average wait time is " << (float)sum1 / n << endl;
    cout << "Average turnaround time is " << (float)sum2 / n << endl;

    return 0;
}
