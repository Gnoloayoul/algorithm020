class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def x(m,n,pre):
            if m>n: return
            if m==0:
                ans.append(pre+")"*n)
                return
            x(m-1,n,pre+"(")
            x(m,n-1,pre+")")
        x(n,n,"")
        return ans