class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        if len(nums) <= 1:
            return [nums]
        else:
            a = []
            for x in list(set(nums)):
                i = nums.index(x)
                xs = nums[:i] + nums[i+1:]
                for p in self.permuteUnique(xs):
                    a.append([x] + p)
            return a