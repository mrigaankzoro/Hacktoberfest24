#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndexMap;
    int left = 0;  // left pointer of the sliding window
    int maxLength = 0;  // stores the maximum length of the substring without repeating characters
    
    // Iterate through the string with the right pointer
    for (int right = 0; right < s.length(); right++) {
        char currentChar = s[right];
        
        // If the current character is already in the map and its index is within the current window,
        // move the left pointer to one position right of the last occurrence of the current character.
        if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= left) {
            left = charIndexMap[currentChar] + 1;
        }
        
        // Update the map with the current character's latest index.
        charIndexMap[currentChar] = right;
        
        // Calculate the length of the current window and update maxLength if necessary.
        maxLength = max(maxLength, right - left + 1);
    }
    
    return maxLength;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    int result = lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    
    return 0;
}
