#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of processes:" << endl;
    cin >> n;

    int at[10], burst[10], burstc[10], tat[10], wt[10];

    // Initializing arrival times to zero
    for (int i = 0; i < n; i++)
    {
        at[i] = 0;
    }

    // Input burst times
    cout << "Enter burst time: ";
    for (int i = 0; i < n; i++)
    {
        cin >> burst[i];
        burstc[i] = burst[i];
    }

    // Calculating turnaround time and updating burst times
    for (int i = 0; i < n; i++)
    {
        tat[i] = burst[i] - at[i];
        if (i < n - 1) // Preventing out-of-bounds access
            burst[i + 1] = burst[i] + burst[i + 1];
    }

    // Calculating wait times
    wt[0] = 0; // Waiting time for the first process is 0
    for (int i = 1; i < n; i++)
    {
        wt[i] = burst[i - 1];
    }

    float sum1 = 0, sum2 = 0;

    // Displaying wait times and turnaround times
    for (int i = 0; i < n; i++)
    {
        cout << "Wait time for process " << i + 1 << " is " << wt[i] << endl;
        cout << "Turnaround time for process " << i + 1 << " is " << tat[i] << endl;
        sum1 += wt[i];
        sum2 += tat[i];
    }

    // Calculating and displaying average wait and turnaround times
    cout << "Average Wait time = " << sum1 / n << endl;
    cout << "Average Turnaround time = " << sum2 / n << endl;

    return 0;
}
