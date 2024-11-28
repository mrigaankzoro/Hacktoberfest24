#include <iostream>
#include <vector>

using namespace std;

class Tribo {
public:
    // DP approach to calculate tribonacci numbers
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        // Create a DP array to store the tribonacci numbers
        vector<int> dp(n + 1);
        dp[0] = 0;  // T(0)
        dp[1] = 1;  // T(1)
        dp[2] = 1;  // T(2)

        // Fill the dp array iteratively
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        // The nth tribonacci number
        return dp[n];
    }
};

int main() {
    Tribo t;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = t.tribonacci(n);
    cout << "Tribonacci of " << n << " is: " << result << endl;

    return 0;
}
