class Solution:
    def __init__(self):
        self.inorder_index = {}
        self.preorder = []
        self.inorder = []
        self.n = 0
    
    def build(self, pi, pj, ii, ij):
        if pi == pj:
            return TreeNode(self.preorder[pi])
        if pi > pj:
            return None
        root_val = self.preorder[pi]
        root = TreeNode(root_val)
        pivot = self.inorder_index[root_val]
        root.left = self.build(pi+1, pi+pivot-ii, ii, pivot-1)
        root.right = self.build(pi+1+pivot-ii, pj, pivot+1, ij)
        return root
        
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        self.n = len(preorder)
        if not self.n: return None
        self.preorder = preorder 
        for i,e in enumerate(inorder):
            self.inorder_index[e] = i
        return self.build(0, self.n-1, 0, self.n-1)
        