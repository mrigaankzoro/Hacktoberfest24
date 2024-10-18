#include <iostream>
#include <vector>  // Change to include vector instead of map

using namespace std;

class Tribo {
public:
    int calc(int n, vector<int> &memo) {  // Change parameter type to vector
        if (memo[n] != -1) {  // Check if already computed
            return memo[n];
        } else {
            int sol = calc(n - 1, memo) + calc(n - 2, memo) + calc(n - 3, memo);
            memo[n] = sol;
            return sol;
        }
    }

    int tribonacci(int n) {
        // Input validation
        if (n < 0) {
            throw invalid_argument("Input must be a non-negative integer."); // Add input validation
        }
        
        vector<int> memo(n + 1, -1); // Initialize memoization vector with -1
        memo[0] = 0;
        if (n > 0) memo[1] = 1; // Ensure we only assign if n > 0
        if (n > 1) memo[2] = 1; // Ensure we only assign if n > 1
        
        return calc(n, memo);
    }
};

int main() {
    Tribo t;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    try {
        int result = t.tribonacci(n);
        cout << "Tribonacci of " << n << " is: " << result << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl; // Catch and print input validation error
    }

    return 0;
}
