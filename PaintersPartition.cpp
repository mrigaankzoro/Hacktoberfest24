#include <iostream>
#include <vector>
using namespace std;
bool isFeasible(const vector<int>& boards, int painters, int maxTime){
    int painterCount = 1;  
    int currentBoardSum = 0;       
    for (int board : boards) {
        if (currentBoardSum + board > maxTime) {
            painterCount++;
            currentBoardSum = board;  
            if (painterCount > painters || board > maxTime) {
                return false;
            }
        } else {
            currentBoardSum += board; 
        }
    }
    return true;  
}
int MinTimeToPaint(const vector<int>& boards, int painters) { 
    int n = boards.size();
    if (painters > n) {
        return -1; 
    }
    int totalSum = 0;
    for (int board : boards) {
        totalSum += board; 
    }
    int start = 0;  
    int end = totalSum;  
    int result = -1;
  
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isFeasible(boards, painters, mid)) {
            result = mid;   
            end = mid - 1;  
        } else {
            start = mid + 1;   
        }
    }
    return result; 
}

int main() {
    int n;
    int painters;

    cout << "Enter the number of boards: ";
    cin >> n;
    vector<int> boards(n);
    cout << "Enter the lengths of the boards: ";
    for (int i = 0; i < n; i++) {
        cin >> boards[i];
    }
    cout << "Enter the number of painters: ";
    cin >> painters;
    int minTime = MinTimeToPaint(boards, painters);
    if (minTime != -1) {
        cout << "Minimum time required to paint all boards: " << minTime << endl;
    } else {
        cout << "Not enough painters to paint all boards." << endl;
    }
    return 0;
}
