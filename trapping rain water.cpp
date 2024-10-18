#include <iostream>
#include <vector>
#include <algorithm>

int trap(std::vector<int>& height) {
    if (height.empty()) return 0;

    int n = height.size();
    std::vector<int> leftMax(n);
    std::vector<int> rightMax(n);

    // Fill leftMax array
    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = std::max(leftMax[i - 1], height[i]);
    }

    // Fill rightMax array
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = std::max(rightMax[i + 1], height[i]);
    }

    // Calculate trapped water
    int totalWater = 0;
    for (int i = 0; i < n; ++i) {
        totalWater += std::min(leftMax[i], rightMax[i]) - height[i];
    }

    return totalWater;
}

int main() {
    std::vector<int> height;
    int n, h;

    std::cout << "Enter the number of bars: ";
    std::cin >> n;
    std::cout << "Enter the heights of the bars: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> h;
        height.push_back(h);
    }

    int result = trap(height);
    std::cout << "Total trapped rainwater: " << result << " units." << std::endl;

    return 0;
}
