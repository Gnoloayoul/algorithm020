class Solution:
    def __init__(self):
        self.l=[]
        self.mul = {  
        '2': ['a','b','c'],
        '3' : ['d','e','f'],
        '4' : ['g','h','i'],
        '5' : ['j','k','l'],
        '6' : ['m','n','o'],
        '7' : ['p','q','r','s'],
        '8' : ['t','u','v'],
        '9' : ['w','x','y','z']   
             }
    def AppendremainderLetter(self,s1:str,s:str):
        if len(s)>1:            
            for item in self.mul[s[0]]:
                self.AppendremainderLetter(s1+item,s[1:])
        elif len(s)==1:
            for item in self.mul[s[0]]:
                self.l.append(s1+item)
    def letterCombinations(self, digits: str) -> List[str]:
        self.AppendremainderLetter('',digits)
        return self.l