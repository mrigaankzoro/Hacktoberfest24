#include <iostream>
#include <vector>
using namespace std;

vector<int> dp; // Vector to store previously calculated Fibonacci values

int f(int n) {
    // Base cases for Fibonacci
    if (n == 0 || n == 1)
        return n;

    // Check if Fibonacci of n is already calculated (memoization)
    if (dp[n] != -1)
        return dp[n];

    // Recursive calculation using memoization
    dp[n] = f(n - 1) + f(n - 2);
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Initialize dp vector with -1, indicating uncalculated values
    dp.resize(n + 1, -1);

    // Output the nth Fibonacci number
    cout << "Fibonacci of " << n << " is: " << f(n)

