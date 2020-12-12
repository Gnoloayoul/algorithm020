#greedy
class Solution:
    def findContentChildren(self, need: List[int], have: List[int], i = 0, j = 0) -> int:
        need.sort()
        have.sort()
        while i < len(need) and j < len(have):
            if need[i] <= have[j]:
                i += 1
            j += 1
        return i