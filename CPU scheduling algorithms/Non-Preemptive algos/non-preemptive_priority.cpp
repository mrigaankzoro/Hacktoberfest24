#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], burst[n], wt[n], tat[n], priority[n];
    int time = 0;

    // Input arrival time, burst time, and priority for each process
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> at[i];
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> burst[i];
        cout << "Enter priority for process " << i + 1 << ": ";
        cin >> priority[i];
    }

    // Priority-based scheduling
    for (int i = 0; i < n; i++)
    {
        int lp = priority[i]; // Assume the current priority is the lowest

        // Find the process with the highest priority that has arrived
        for (int j = 0; j < n; j++)
        {
            if (lp > priority[j] && at[j] <= time)
            {
                lp = priority[j];
            }
        }

        // Schedule the process with the highest priority
        for (int k = 0; k < n; k++)
        {
            if (lp == priority[k])
            {
                wt[k] = time - at[k]; // Calculate the waiting time
                priority[k] = 999999; // Mark the process as completed by assigning a large priority
                time += burst[k];     // Update the total time
                tat[k] = wt[k] + burst[k]; // Calculate turnaround time
                break;
            }
        }
    }

    float sum1 = 0;
    float sum2 = 0;

    // Calculate the total waiting time and turnaround time
    for (int i = 0; i < n; i++)
    {
        sum1 += wt[i];
        sum2 += tat[i];
        cout << "Wait time for process " << i + 1 << " is " << wt[i] << endl;
        cout << "Turn around time for process " << i + 1 << " is " << tat[i] << endl;
    }

    // Output the average waiting time and turnaround time
    cout << "\nAverage wait time = " << sum1 / n << endl;
    cout << "Average turn around time = " << sum2 / n << endl;

    return 0;
}
