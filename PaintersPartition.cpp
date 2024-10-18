#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if it's possible to paint all boards in the given 'maxTime' with 'k' painters
bool isFeasible(const vector<int>& boards, int k, int maxTime) {
    int painters = 1; // At least one painter is required
    int currentTime = 0;

    for (int board : boards) {
        if (currentTime + board > maxTime) {
            painters++;  // Assign a new painter
            currentTime = board;  // Start the new painter's task with this board
            if (painters > k || board > maxTime) {  // If more painters are needed or board length exceeds maxTime
                return false;
            }
        } else {
            currentTime += board;  // Continue painting with the current painter
        }
    }
    return true;  // If all boards are painted within the given maxTime
}

// Function to find the minimum time required to paint all boards by k painters
int paintersPartition(const vector<int>& boards, int k) {
    int n = boards.size();
    if (n == 0) return 0; // No boards to paint
    if (k > n) return -1; // More painters than boards doesn't make sense

    int totalLength = 0, maxBoard = 0;
    
    // Calculate the total length of all boards and find the maximum board length
    for (int board : boards) {
        totalLength += board;
        maxBoard = max(maxBoard, board);
    }
    
    // Binary search for the minimum feasible time
    int low = maxBoard;  // The minimum time must be at least the length of the largest board
    int high = totalLength;  // The maximum time is if one painter paints all boards
    int result = high;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isFeasible(boards, k, mid)) {
            result = mid;  // If it's possible to paint with this time, try a smaller value
            high = mid - 1;
        } else {
            low = mid + 1;  // Otherwise, increase the time
        }
    }
    
    return result;
}

int main() {
    int n, painters;
    
    cout << "Enter the number of boards: ";
    cin >> n;
    vector<int> boards(n);

    cout << "Enter the lengths of the boards: ";
    for (int i = 0; i < n; i++) {
        cin >> boards[i];
    }

    cout << "Enter the number of painters: ";
    cin >> painters;

    int minTime = paintersPartition(boards, painters);
    
    if (minTime != -1) {
        cout << "Minimum time required to paint all boards: " << minTime << " units" << endl;
    } else {
        cout << "Not enough painters to paint all boards." << endl;
    }
    
    return 0;
}
