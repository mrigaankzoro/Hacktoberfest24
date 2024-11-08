/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/* Time Complexity: O(2N) where N is the number of nodes in the Binary Tree.
   The time complexity is linear, as each node is visited at most 
   twice (once for establishing the temporary link and once for reverting it).

   Space Complexity : O(1) No additional space is used hence maintaining a space complexity of O(1).
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result; 
        TreeNode* current = root;

        while (current) {
            if (!current->left) {
                result.push_back(current->val); // Visit the node
                current = current->right; // Move to the right child
            } else {
                // Find the rightmost node in the left subtree
                TreeNode* predecessor = current->left;
                while (predecessor->right && predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                // Make a temporary link from the predecessor to the current node
                if (!predecessor->right) {
                    predecessor->right = current; // Establish temporary link
                    result.push_back(current->val); // Visit the node
                    current = current->left; // Move to the left child
                } else {
                    // Restore the original tree structure
                    predecessor->right = nullptr; // Remove temporary link
                    current = current->right; // Move to the right child
                }
            }
        }
        return result;
    }
};
