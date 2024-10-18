#include<bits/stdc++.h>
using namespace std;

// Node structure for the BST
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a new value into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function to search for a value in the BST
bool search(TreeNode* root, int val) {
    if (root == nullptr) {
        return false;
    }
    if (root->val == val) {
        return true;
    } 
    return val < root->val ? search(root->left, val) : search(root->right, val);
}

// Function for in-order traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Main function to demonstrate BST operations
int main() {
    TreeNode* root = nullptr;
    
    // Inserting values into the BST
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 8);
    insert(root, 1);
    insert(root, 4);

    // Searching for values in the BST
    cout << "Searching for 4: " << (search(root, 4) ? "Found" : "Not Found") << endl;
    cout << "Searching for 10: " << (search(root, 10) ? "Found" : "Not Found") << endl;

    // In-order traversal of the BST
    cout << "In-order traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
