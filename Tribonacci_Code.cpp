#include <iostream>
#include <vector>
using namespace std;
int tribonacci(int n) {
    if (n < 0) {
        throw invalid_argument("Input cannot be negative.");
    }
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    vector<int> dp(n + 1);
    dp[0] = 0; 
    dp[1] = 1; 
    dp[2] = 1; 
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter a non-negative integer for the nth Tribonacci number: ";
    while (true) {
        cin >> n;

        if (cin.fail() || n < 0) {
            cout << "Invalid input. Please enter a non-negative integer: ";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        } else {
            break; 
        }
    }

    int result = tribonacci(n);
    cout << "The " << n << "th Tribonacci number is: " << result << endl;
    return 0;
}
