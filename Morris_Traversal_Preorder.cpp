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

/*Time Complexity: O(2N) where N is the number of nodes in the Binary Tree.
                The time complexity is linear, as each node is visited at most 
                twice (once for establishing the temporary link and once for reverting it).

  Space Complexity : O(1) No additional space is used hence maintaining a space complexity of O(1).
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder ; 
        TreeNode* cur=root;
        while(cur!=NULL){
          
            if(cur->left ==NULL) {
                preorder.push_back(cur->val);
                cur = cur->right ;
            }
            else{
                TreeNode* prev= cur->left;
                while(prev->right && prev->right!=cur){
                    prev= prev->right;
                }
                if(prev->right == NULL) {
                    prev->right = cur; //make temporary link to root node from leftmost node of left subtree
                    preorder.push_back(cur->val);
                    cur= cur->left;
                }
                if(prev->right == cur){
                    prev->right = NULL; //remove temporary link to root node
                    cur = cur->right; 
                }
            }
        }
        return preorder;
    }
};
