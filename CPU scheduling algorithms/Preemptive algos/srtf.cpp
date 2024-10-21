#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> at(n), burst(n), burstc(n), wt(n), tat(n), completed(n, 0);
    int time = 0, count = 0, index = -1;
    float sum1 = 0, sum2 = 0;

    // Input arrival time and burst time for each process
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> at[i];
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> burst[i];
        burstc[i] = burst[i]; // Copy burst time for remaining time tracking
    }

    // Shortest Remaining Time First (SRTF) scheduling
    while (count < n)
    {
        int srt = INT_MAX;
        index = -1;

        // Find the process with the shortest remaining time
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= time && completed[i] == 0 && burstc[i] < srt)
            {
                srt = burstc[i];
                index = i;
            }
        }

        // If a valid process is found, execute it for one unit of time
        if (index != -1)
        {
            burstc[index]--; // Decrease the remaining burst time
            time++;          // Increment the current time

            // If the process is completed
            if (burstc[index] == 0)
            {
                completed[index] = 1; // Mark as completed
                count++;              // Increase the count of completed processes
                tat[index] = time - at[index]; // Calculate turnaround time
                wt[index] = tat[index] - burst[index]; // Calculate waiting time
                sum1 += wt[index];
                sum2 += tat[index];
            }
        }
        else
        {
            time++; // Increment time if no process was executed
        }
    }

    // Output the waiting time and turnaround time for each process
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
