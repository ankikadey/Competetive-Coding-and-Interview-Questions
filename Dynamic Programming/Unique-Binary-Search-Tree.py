class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def generateTrees(self, A):
        if A == 0:
            return []
        return self.generateTreesHelper(1, A)

    def generateTreesHelper(self, start, end):
        trees = []
        if start > end:
            trees.append(None)
            return trees

        for i in range(start, end + 1):
            left_subtrees = self.generateTreesHelper(start, i - 1)
            right_subtrees = self.generateTreesHelper(i + 1, end)

            for left_tree in left_subtrees:
                for right_tree in right_subtrees:
                    root = TreeNode(i)
                    root.left = left_tree
                    root.right = right_tree
                    trees.append(root)

        return trees

# Example usage:
A = 3
solution = Solution()
result = solution.generateTrees(A)
