class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        self.answer = []
        self.k = k
        self.n = n
        
        self.generateKPairs(solution=[], num=1)
        
        return self.answer
    
    def generateKPairs(self, solution, num):
        if len(solution) == self.k:
            self.answer.append(solution)
            
        elif len(solution) < self.k:
            for i in range(num, self.n + 1):
                self.generateKPairs(solution + [i], i+1)