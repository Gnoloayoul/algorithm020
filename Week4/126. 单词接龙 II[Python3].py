class Solution: #two-end BFS
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        if endWord not in wordList: return []
        
        graph = dict()
        for word in wordList:
            for i in range(len(word)):
                graph.setdefault(word[:i] + "*" + word[i+1:], []).append(word)
                
        ans = []
        front0, front1 = {beginWord: [[beginWord]]}, {endWord:[[endWord]]} #word & sequences ending in word
        seen = {beginWord, endWord}
        reverse = False 
        
        while front0 and front1 and not ans:
            if len(front0) > len(front1): front0, front1, reverse = front1, front0, not reverse 
            temp = dict()
            for word, seq in front0.items(): 
                for i in range(len(word)): 
                    for node in graph.get(word[:i] + "*" + word[i+1:], []): 
                        if node in front1: 
                            ans.extend([y + x[::-1] if reverse else x + y[::-1] for x in seq for y in front1[node]])
                        if node in seen: continue
                        for x in seq: 
                            temp.setdefault(node, []).append(x + [node])
            seen |= set(temp.keys()) #has to be updated level-by-level
            front0 = temp 
        return ans 