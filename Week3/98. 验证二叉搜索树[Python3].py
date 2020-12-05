class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def dp(node, low, hight) :
            if not node : return True
            if node.val >= hight or node.val <= low :
                return False 
            return dp(node.left, low, node.val) and dp(node.right, node.val, hight)
        return dp(root, float(-inf), float(inf))