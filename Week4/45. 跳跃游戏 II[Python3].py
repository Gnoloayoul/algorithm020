class Solution:
    def jump(self, nums: List[int]) -> int:
        if(len(nums)==1):return 0
        if(len(nums)==2):return 1
        ladder = nums[0]
        stairs = nums[0]
      
        jump=1;stored=0
        for i in range(1,len(nums)):
            if(i==len(nums)-1):
                return jump
            if(i+nums[i]>ladder):
                ladder = nums[i]+i
            stairs-=1
            if(stairs==0):
                jump+=1
                stairs=ladder-i