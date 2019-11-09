class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        return self.isValidBSTCore(root, -float('inf'), float('inf') )
    
    def isValidBSTCore(self, root, left, right):
        if root is None:
            return True
        if root.val < right and root.val > left:
            return self.isValidBSTCore(root.left, left, root.val) and self.isValidBSTCore(root.right, root.val, right)
        else:
            return False