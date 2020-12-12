class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        if n == 0 or n == 1: return True
        for i in range(n-2,-1,-1):
            if nums[i] == 0:
                flag = False
                for j in range(i-1,-1,-1):
                    if nums[j]+j > i:
                        flag = True
                        break
                if flag == False:
                    return False
        return True