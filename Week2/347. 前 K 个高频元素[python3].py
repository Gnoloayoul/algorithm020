
class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        counter = {}
        for num in nums:
            if num in counter:
                counter[num] += 1
            else:
                counter[num] = 1
        return sorted(counter, key=lambda x: counter[x], reverse=True)[:k]