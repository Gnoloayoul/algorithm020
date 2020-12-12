class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        d1_dict = collections.defaultdict(list)
        for word in wordList + [beginWord]:
            for i in range(len(word)):
                pattern = list(word)
                pattern[i] = '*'
                d1_dict[''.join(pattern)].append(word)
        observed1 = {beginWord: 1}
        queue1 = collections.deque([(beginWord, 1)])
        observed2 = {endWord: 1}
        queue2 = collections.deque([(endWord, 1)])
        while queue1 and queue2:
            word, length = queue1.popleft()
            for i in range(len(word)):
                pattern = list(word)
                pattern[i] = '*'
                for other in d1_dict[''.join(pattern)]:
                    if other in observed2:
                        return length + observed2[other]
                    if other not in observed1:
                        queue1.append((other, length + 1))
                        observed1[other] = length + 1
            word, length = queue2.popleft()
            for i in range(len(word)):
                pattern = list(word)
                pattern[i] = '*'
                for other in d1_dict[''.join(pattern)]:
                    if other in observed1:
                        return length + observed1[other]
                    if other not in observed2:
                        queue2.append((other, length + 1))
                        observed2[other] = length + 1
        return 0