#not greedy
class Solution:
    	def lemonadeChange(self, bills: List[int]) -> bool:
		cur5=0
		cur10=0
		cur20=0
		for i in bills:
			if i==5:
				cur5+=1
			elif i==10:
				cur5-=1
				cur10+=1
			elif i==20:
				if cur10>=1:
					cur10-=1
					cur20+=1
					cur5-=1
				else:
					cur20+=1
					cur5-=3
			if cur5<0 or cur10<0:
				return False
		return True