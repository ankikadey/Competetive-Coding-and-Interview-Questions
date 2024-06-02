#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

// Structure for tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Vector to store input pairs
vector<pair<int, int>> inp;

// Recursive function to construct binary tree from the given input format
void constructTree(int i, TreeNode* node) {
    if(inp[i].first > -1) {
        node->left = new TreeNode(inp[i].first);
        constructTree(inp[i].first - 1, node->left);
    }
    if(inp[i].second > -1) {
        node->right = new TreeNode(inp[i].second);
        constructTree(inp[i].second - 1, node->right);
    }
}

// Recursive function to return height of any given node
int height(TreeNode *node, int &diameter) {
    // Base case for NULL nodes
    if(!node) return 0;

    // Find height of left and right subtree recursively
    int leftHeight = height(node->left, diameter);
    int rightHeight = height(node->right, diameter);

    // Diameter can be the sum of left and right subtree heights
    diameter = max(diameter, leftHeight + rightHeight);

    // Return height of the current node
    return (max(leftHeight, rightHeight) + 1);
}

// Function to call the recursive height function and return the final answer
int findDiameter(TreeNode *root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() {
    // Reading inputs
    int n;
    cin >> n;
    inp.resize(n);
    for(int i = 0; i < n; i++)
        cin >> inp[i].first >> inp[i].second;
    
    // Defining root node and constructing binary tree
    TreeNode* root = new TreeNode(1);
    constructTree(0, root);

    // Call function to find diameter
    int res = findDiameter(root);

    // Print result
    cout << res << endl;

    return 0;
}
