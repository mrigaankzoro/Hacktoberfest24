#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> G[6001];
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> visited(n + 1, INT_MAX);  // Initialize distances with INT_MAX
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ; // Min-heap

        // Build the graph
        for(int i = 0; i < times.size(); i++) {
            G[times[i][0]].push_back({times[i][2], times[i][1]});
        }

        // Initialize starting point
        PQ.push({0, k});
        visited[k] = 0;

        while(!PQ.empty()) {
            pair<int, int> u = PQ.top();
            PQ.pop();

            int uCost = u.first;
            int uNode = u.second;

            if(uCost > visited[uNode]) continue;

            for(pair<int, int> v : G[uNode]) {
                int vCost = v.first;
                int vNode = v.second;
                int newDist = uCost + vCost;

                if(newDist < visited[vNode]) {
                    visited[vNode] = newDist;
                    PQ.push({newDist, vNode});
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(visited[i] == INT_MAX) return -1;
            ans = max(ans, visited[i]);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4;
    int k = 2;

    int result = solution.networkDelayTime(times, n, k);
    cout << "Network delay time: " << result << endl;

    return 0;
}
