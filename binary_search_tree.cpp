#include <iostream>
using namespace std;

struct Node {
    int key;          
    Node* left;      
    Node* right;      
    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;
    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        }
        return node;
    }

    Node* search(Node* node, int key) {
        if (node == nullptr || node->key == key) {
            return node;
        }

        if (key > node->key) {
            return search(node->right, key);
        }

        return search(node->left, key);
    }

    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left); 
            cout << node->key << " "; 
            inOrder(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}
    void insert(int key) {
        root = insert(root, key);
    }
    bool search(int key) {
        return search(root, key) != nullptr;
    }

    void inOrder() {
        inOrder(root);
        cout << endl; 
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "In-order traversal of the BST: ";
    bst.inOrder();

    int keyToSearch = 40;
    cout << "Searching for " << keyToSearch << ": ";
    cout << (bst.search(keyToSearch) ? "Found" : "Not Found") << endl;

    keyToSearch = 90;
    cout << "Searching for " << keyToSearch << ": ";
    cout << (bst.search(keyToSearch) ? "Found" : "Not Found") << endl;

    return 0;
}
