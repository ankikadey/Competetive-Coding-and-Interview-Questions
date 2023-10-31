#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* A) {
    ListNode* dummy = new ListNode(0);
    dummy->next = A;
    ListNode* prevNode = dummy;

    while (prevNode->next && prevNode->next->next) {
        ListNode* firstNode = prevNode->next;
        ListNode* secondNode = prevNode->next->next;

        // Swapping
        firstNode->next = secondNode->next;
        secondNode->next = firstNode;
        prevNode->next = secondNode;

        // Move to the next pair
        prevNode = firstNode;
    }

    return dummy->next;
}

// Function to print the linked list
void printList(ListNode* node) {
    while (node != NULL) {
        cout << node->val;
        if (node->next) {
            cout << " -> ";
        }
        node = node->next;
    }
    cout << endl;
}

// Main function for testing
int main() {
    ListNode* A1 = new ListNode(1);
    A1->next = new ListNode(2);
    A1->next->next = new ListNode(3);
    A1->next->next->next = new ListNode(4);

    ListNode* A2 = new ListNode(7);
    A2->next = new ListNode(2);
    A2->next->next = new ListNode(1);

    // Testing the swapPairs function
    cout << "Input 1: ";
    printList(A1);
    ListNode* result1 = swapPairs(A1);
    cout << "Output 1: ";
    printList(result1);

    cout << "Input 2: ";
    printList(A2);
    ListNode* result2 = swapPairs(A2);
    cout << "Output 2: ";
    printList(result2);

    return 0;
}
