#include <iostream>
#include <map>

using namespace std;

class TribonacciCalculator {
public:
    // A helper function to calculate the Tribonacci number with memoization
    int calculateTribonacci(int n, map<int, int> &memo) {
        // Check if result for the current 'n' is already calculated (memoized)
        if (memo.find(n) != memo.end()) {
            return memo[n];
        } else {
            // Recursive relation: T(n) = T(n-1) + T(n-2) + T(n-3)
            int result = calculateTribonacci(n - 1, memo) + calculateTribonacci(n - 2, memo) + calculateTribonacci(n - 3, memo);
            // Store the result in memoization map for future use
            memo[n] = result;
            return result;
        }
    }

    // Public function to calculate the Tribonacci number for 'n'
    int tribonacci(int n) {
        // Memoization map to store already computed Tribonacci numbers
        map<int, int> memo;
        // Base cases for Tribonacci sequence
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        
        // Start the calculation using the helper function
        return calculateTribonacci(n, memo);
    }
};

int main() {
    // Create an instance of the TribonacciCalculator class
    TribonacciCalculator calculator;

    // Input from the user
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Compute the Tribonacci value for 'n'
    int result = calculator.tribonacci(n);

    // Output the result
    cout << "Tribonacci of " << n << " is: " << result << endl;

    return 0;
}
