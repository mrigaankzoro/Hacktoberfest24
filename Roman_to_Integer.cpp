#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(std::string s) {
        unordered_map<char, int> mpp = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int ans = mpp[s[0]];
        vector<int> sum;
        sum.push_back(ans);
        
        int i = 1;
        while (i < s.size()) {
            if (mpp[s[i]] > mpp[s[i - 1]]) {
                ans = mpp[s[i]] - mpp[s[i - 1]];
                sum.pop_back();
                sum.push_back(ans);
                i++;
            } else {
                ans = mpp[s[i]];
                sum.push_back(ans);
                i++;
            }
        }
        
        int total = 0;
        for (int i = 0; i < sum.size(); i++) {
            total += sum[i];
        }
        
        return total;
    }
};

int main() {
    
    Solution solution;
    string roman;
    cout << "Enter a Roman numeral: ";
    cin >> roman;
    
    int result = solution.romanToInt(roman);
    cout << "The integer value of the Roman numeral is: " << result << std::endl;
    
    return 0;
}