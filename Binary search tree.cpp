#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void displayTree(struct Node* root, int space) {
    if (root == NULL) return;

    space += 5;

    displayTree(root->right, space);

    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    displayTree(root->left, space);
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d -> ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d -> ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d -> ", root->data);
    }
}

void selectTraversal(struct Node* root) {
    int choice;
    
    printf("Choose a traversal method:\n");
    printf("1. In-order\n");
    printf("2. Pre-order\n");
    printf("3. Post-order\n");
    printf("Enter your choice (1/2/3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("In-order Traversal: ");
            inorderTraversal(root);
            break;
        case 2:
            printf("Pre-order Traversal: ");
            preorderTraversal(root);
            break;
        case 3:
            printf("Post-order Traversal: ");
            postorderTraversal(root);
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }
    printf("NULL\n");  
}

int main() {
    struct Node* root = NULL;


    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);


    printf("Tree structure:\n");
    displayTree(root, 0);


    selectTraversal(root);

    return 0;
}
