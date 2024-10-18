#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> preorder; 
        TreeNode* cur = root;
        
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                preorder.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;
                while (prev->right != nullptr && prev->right != cur) {
                    prev = prev->right;
                }
                if (prev->right == nullptr) {
                    prev->right = cur;
                    preorder.push_back(cur->val);
                    cur = cur->left;
                }
                if (prev->right == cur) {
                    prev->right = nullptr;
                    cur = cur->right; 
                }
            }
        }
        return preorder;
    }
};
