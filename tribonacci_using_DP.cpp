#include <iostream>
#include <vector>

int tribonacci(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    // Create a vector to store the Tribonacci numbers
    std::vector<int> dp(n + 1, 0);
    
    // Initialize base cases
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    // Fill the dp vector using the Tribonacci formula
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    // Return the nth Tribonacci number
    return dp[n];
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    int result = tribonacci(n);
    std::cout << "The " << n << "th Tribonacci number is: " << result << std::endl;

    return 0;
}
