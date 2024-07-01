//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int Count = 0;
    int pathSum(TreeNode *a, int targetSum)
    {
        if (!a)
            return 0;

        // Count All Paths From a
        PathFromRoot(a, targetSum, 0, Count);

        // Count All Paths From a's Left Subtree
        pathSum(a->left, targetSum);

        // Count All Paths From a's Right Subtree
        pathSum(a->right, targetSum);

        return Count;
    }

private:
    void PathFromRoot(TreeNode *a, int target, long Sum, int &Count)
    {

        if (!a)
            return;

        Sum += a->val;

        if (Sum == target)
            Count++;
        PathFromRoot(a->left, target, Sum, Count);
        PathFromRoot(a->right, target, Sum, Count);
    }
};