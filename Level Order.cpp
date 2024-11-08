
#include<bits/stdc++.h>
using namespace std;


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

  vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);
        
        if(root==NULL){
            return v;
        }
        while(!q.empty()){
           
            vector<int> j;
            int size = q.size();
            for(int i=0;i<size;i++){
                 TreeNode* temp = q.front();
                q.pop();
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                 q.push(temp->right);
            
            j.push_back(temp->val);
            cout<<temp->val<<" ";
            
                
            }
            v.push_back(j);
                
            
        }
        return v;
    }
    
    
    


int main(){

    TreeNode *tree = new TreeNode();
     
     tree->left = new TreeNode(5);
     tree->right = new TreeNode(4);
     levelOrder(tree);
    return 0;
}


