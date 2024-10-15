#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Count the number of nodes in the list
        int cnt = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            cnt++;
        }
        
        // If the number of nodes is less than k, return the head as it is
        if (cnt < k) {
            return head;
        }

        // Reverse the first k nodes
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* forward = nullptr;
        int c = 0;

        while (current != nullptr && c < k) {
            forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
            c++;
        }

        // Recursively call the function for the next group
        if (forward != nullptr) {
            head->next = reverseKGroup(forward, k);
        }

        // prev is the new head of the reversed group
        return prev;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list from a given node
void printLinkedList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    // Sample input
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create the linked list
    ListNode* head = createLinkedList(arr, size);

    // Create an instance of the Solution class
    Solution solution;

    // Define the value of k
    int k = 2;

    // Reverse the nodes in k-groups
    ListNode* newHead = solution.reverseKGroup(head, k);

    // Print the new linked list
    printLinkedList(newHead);

    return 0;
}
