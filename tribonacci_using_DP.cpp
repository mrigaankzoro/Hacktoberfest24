#include <iostream>
#include <map>

using namespace std;

class Tribo {
public:
    int calc(int n, map<int, int> &memo) {
        if (memo.find(n) != memo.end()) {
            return memo[n];
        } else {
            int sol = calc(n - 1, memo) + calc(n - 2, memo) + calc(n - 3, memo);
            memo[n] = sol;
            return sol;
        }
    }

    int tribonacci(int n) {
        map<int, int> memo;
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        
        return calc(n, memo);
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
