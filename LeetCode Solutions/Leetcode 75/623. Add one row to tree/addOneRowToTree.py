from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        if d == 1:
            new_root = TreeNode(v)
            new_root.left = root
            return new_root
        
        depth = 1
        queue = deque([root])

        while queue:
            size = len(queue)
            for _ in range(size):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                if depth == d - 1:
                    cached_left = node.left
                    cached_right = node.right
                    node.left = TreeNode(v)
                    node.right = TreeNode(v)
                    node.left.left = cached_left
                    node.right.right = cached_right
            if depth == d - 1:
                break
            depth += 1

        return root

# Example usage
if __name__ == "__main__":
    # Creating a binary tree
    root = TreeNode(4)
    root.left = TreeNode(2)
    root.right = TreeNode(6)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(1)
    root.right.left = TreeNode(5)

    # Adding a row with value 1 at depth 2
    sol = Solution()
    new_root = sol.addOneRow(root, 1, 2)

    # Printing the modified binary tree
    def print_tree(node):
        if node:
            print(node.val, end=" ")
            print_tree(node.left)
            print_tree(node.right)

    print("Modified Tree:")
    print_tree(new_root)
