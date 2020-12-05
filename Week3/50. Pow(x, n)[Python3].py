class Solution:
    def myPow(self, x: float, n: int) -> float:
        result=self.exp(x,abs(n))
        return result if n>=0 else 1/result
        
    def exp(self, x: float, n: int) -> float:
        if n==0:
            return 1
        return self.exp(x*x,n//2) if n%2==0 else x*self.exp(x*x,n//2)