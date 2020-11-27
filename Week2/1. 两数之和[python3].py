class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        memory = {}
        for i, e in enumerate(nums):
            if e in memory: return (memory[e], i)
            memory[(target - e)] = i
        return []