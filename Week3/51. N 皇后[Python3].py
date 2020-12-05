class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        #recursion terminator
        if root is None : return None
        #process logic in current level
        if root.val == p.val : return p
        elif root.val == q.val : return q
        #drill down
        else :
            isLeft = self.lowestCommonAncestor(root.left, p, q)
            isRight = self.lowestCommonAncestor(root.right, p, q)
            if isLeft == None or isRight == None :
                return isLeft or isRight
            else : 
                return root
        #revert the current level status