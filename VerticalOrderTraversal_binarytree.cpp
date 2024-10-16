#include<bits/stdc++.h>
using namespace std;

// constructing class to define structure of a tree node 
class TreeNode{
public:
 int val;
 TreeNode* left;
 TreeNode* right;
 TreeNode(): val(0), left(nullptr), right(nullptr) {}
 TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

// function for vertical order traversal of binary tree
vector<vector<int>> verticalOrderTraversal(TreeNode* root){
  // edge case: if tree is empty
  if(root == nullptr) return {};
  
  // map to store nodes grouped by their horizontal(x) and vertical(y) positions
  map<int,map<int,multiset<int>>> mpp;
  // queue for traversal: stores nodes and its position(x,y)
  queue<pair<TreeNode*,pair<int,int>>> q;
  // starting traversal from root at position(0,0)
  q.push({root,{0,0}});
  
  // bfs traversal
  while(!q.empty()){
    auto p = q.front(); // get first node
    q.pop(); // remove it from queue
    TreeNode* node = p.first; // current node
    int x = p.second.first; // horizontal distance
    int y = p.second.second; // vertical distance
    mpp[x][y].insert(node->val); // insert nodes's value into the multiset corresponding to its position(x,y)
    // if there's a left child, push it to the queue with position(x-1, y+1)
    if(node->left) q.push({node->left,{x-1,y+1}});
    // if there's a right child, push it to the queue with position(x+1, y+1)
    if(node->right) q.push({node->right,{x+1,y+1}});
  }
  
  // vector of vectors to store nodes in vertical order
  vector<vector<int>> ans;
  // traverse map by horizontal distance(x)
  for(auto it: mpp){
    // traverse through all levels (y) for the current x and insert nodes
    vector<int> nodes;
    for(auto q: it.second){
      nodes.insert(nodes.end(),q.second.begin(), q.second.end());
    }
    // add the current vertical line nodes to the result
    ans.push_back(nodes);
  }
  // return the result
  return ans;
}

// main function to take input(currently empty)
int main(){

  return 0;
}
