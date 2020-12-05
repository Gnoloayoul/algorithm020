class Solution:
    
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root is None:
            return None
        
        if root.val == p.val:
            return p
        elif root.val == q.val:
            return q
        else:
            isFoundLeft = self.lowestCommonAncestor(root.left, p, q)
            isFoundRight = self.lowestCommonAncestor(root.right, p, q)
            if isFoundLeft is None or isFoundRight is None:
                return isFoundLeft or isFoundRight
            else:
                return root