#include <iostream>
#include <vector>
#include <algorithm>
#include <memory> // For std::unique_ptr

using namespace std;

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to find the middle node of a linked list using the fast and slow pointer technique
ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    // Move fast pointer two steps and slow pointer one step until fast reaches the end
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Slow pointer now points to the middle node
    return slow;
}

// Function to recursively construct a linked list from a vector of integers
ListNode *constructLL(const vector<int> &arr, int si)
{
    if (si == arr.size())
    {
        return nullptr;
    }

    // Create a new list node with the current element
    ListNode *head = new ListNode(arr[si]);

    // Recursively construct the rest of the list and link it to the current node
    head->next = constructLL(arr, si + 1);

    return head;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // Sort the vector
    sort(arr.begin(), arr.end());

    // Construct the linked list from the sorted vector
    ListNode *head = constructLL(arr, 0);

    // Find the middle node of the linked list
    ListNode *ans = middleNode(head);

    // Output the value of the middle node
    cout << ans->val << endl;

    // Clean up memory to avoid leaks
    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
