class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        ans = []
        def dfs(node) : 
            if not node : return
            ans.append(node.val)
            for i in node.children : dfs(i)
        dfs(root)
        return ans