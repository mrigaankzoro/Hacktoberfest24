#include <bits/stdc++.h>
using namespace std;

// returns true if there is a triplet with a sum equal 
// to 'sum' present in arr. Also, prints the triplet 
bool find3Numbers(vector<int>& arr, int sum) 
{
    int n = arr.size();
    
    // Fix the first element as arr[i] 
    for (int i = 0; i < n - 2; i++)
    { 
        // Fix the second element as arr[j] 
        for (int j = i + 1; j < n - 1; j++)
        { 
            // Now look for the third number 
            for (int k = j + 1; k < n; k++)
            { 
                if (arr[i] + arr[j] + arr[k] == sum)
                { 
                    cout << "Triplet is " << arr[i] <<
                        ", " << arr[j] << ", " << arr[k]; 
                    return true; 
                } 
            } 
        } 
    } 

    // If we reach here, then no triplet was found 
    return false; 
} 

//Driver code
int main() 
{ 
    vector<int> arr = { 1, 4, 45, 6, 10, 8 }; 
    int sum = 22; 
    find3Numbers(arr, sum); 
    return 0; 
}
