class Solution:
    def permute(self, nums):
        res = []
        res1= []
        def backtrack(res):
            if len(res) == len(nums):
                res1.append(res)
                return
            for i in nums:
                if i not in res:
                    backtrack(res+[i])
            return
        
        backtrack(res)
        return res1