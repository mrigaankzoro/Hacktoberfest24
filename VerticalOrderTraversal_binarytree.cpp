#include <bits/stdc++.h>
using namespace std;

// Class to define the structure of a tree node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Function for vertical order traversal of binary tree
vector<vector<int>> verticalOrderTraversal(TreeNode* root) {
    // Edge case: if tree is empty
    if (root == nullptr) return {};

    // Map to store nodes grouped by their horizontal (x) and vertical (y) positions
    map<int, map<int, multiset<int>>> mpp; // x -> (y -> multiset of values)
    // Queue for traversal: stores pairs of nodes and their positions (x, y)
    queue<pair<TreeNode*, pair<int, int>>> q;

    // Starting traversal from root at position (0, 0)
    q.push({root, {0, 0}});

    // BFS traversal
    while (!q.empty()) {
        auto [node, pos] = q.front();
        q.pop();
        int x = pos.first; // horizontal distance
        int y = pos.second; // vertical distance

        // Insert node's value into the multiset corresponding to its position (x, y)
        mpp[x][y].insert(node->val);

        // If there's a left child, push it to the queue with position (x - 1, y + 1)
        if (node->left) q.push({node->left, {x - 1, y + 1}});
        // If there's a right child, push it to the queue with position (x + 1, y + 1)
        if (node->right) q.push({node->right, {x + 1, y + 1}});
    }

    // Vector of vectors to store nodes in vertical order
    vector<vector<int>> ans;

    // Traverse map by horizontal distance (x)
    for (const auto& [x, yMap] : mpp) {
        vector<int> verticalNodes;
        // Traverse through all levels (y) for the current x and insert nodes
        for (const auto& [y, values] : yMap) {
            verticalNodes.insert(verticalNodes.end(), values.begin(), values.end());
        }
        // Add the current vertical line nodes to the result
        ans.push_back(verticalNodes);
    }

    // Return the result
    return ans;
}

// Main function for testing
int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    vector<vector<int>> result = verticalOrderTraversal(root);
    
    // Output the result
    for (const auto& column : result) {
        for (int val : column) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Cleanup
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
