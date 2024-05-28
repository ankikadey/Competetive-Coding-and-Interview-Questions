#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* swapNodes(ListNode* head, int k) {
    // Count the length of the linked list
    int length = 0;
    ListNode* curr = head;
    while (curr) {
        length++;
        curr = curr->next;
    }

    // Find the kth node from the beginning
    ListNode* kth_from_beginning = head;
    for (int i = 1; i < k; ++i) {
        kth_from_beginning = kth_from_beginning->next;
    }

    // Find the kth node from the end
    ListNode* kth_from_end = head;
    for (int i = 0; i < length - k; ++i) {
        kth_from_end = kth_from_end->next;
    }

    // Swap the values
    swap(kth_from_beginning->val, kth_from_end->val);

    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    int k;
    cin >> k;

    // Create the linked list
    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; ++i) {
        curr->next = new ListNode(values[i]);
        curr = curr->next;
    }

    // Swap nodes
    head = swapNodes(head, k);

    // Output
    printLinkedList(head);

    // Free memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
