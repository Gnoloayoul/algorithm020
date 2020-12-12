#DFS
class Solution:
    def updateBoard(self, board, click):
        r, c = click
        if not board:
            return board
        if board[r][c] == 'M':
            board[r][c] = 'X'
        else:
            m, n = len(board), len(board[0])
            get8Adjs = lambda r, c: [(r-1,c),(r+1,c),(r,c-1),(r,c+1),(r-1,c+1),(r-1,c-1),(r+1,c+1),(r+1,c-1),]            
            def dfsUpdate(r, c):
                adjs = [(r1, c1) for r1, c1 in get8Adjs(r, c) if 0 <= r1 < m and 0 <= c1 < n]
                ms = [(r1, c1) for r1, c1 in adjs if board[r1][c1] == 'M']
                if not ms:
                    board[r][c] = 'B'
                    for r1, c1 in adjs:
                        if board[r1][c1] == 'E':
                            dfsUpdate(r1, c1)
                else:
                    board[r][c] = str(len(ms))
            dfsUpdate(*click)
        return board

#BFS
class Solution:
    def updateBoard(self, board, click):
        r, c = click
        if not board:
            return board
        if board[r][c] == 'M':
            board[r][c] = 'X'
        else:
            m, n = len(board), len(board[0])
            q = [click]
            get8Adjs = lambda r, c: [(r-1,c),(r+1,c),(r,c-1),(r,c+1),(r-1,c+1),(r-1,c-1),(r+1,c+1),(r+1,c-1),]
            for r, c in q:
                if board[r][c] != 'E':
                    continue  # NOTE: VERY IMPORTANT!!
                adjs = [(r1, c1) for r1, c1 in get8Adjs(r, c) if 0 <= r1 < m and 0 <= c1 < n]
                ms = [(r1, c1) for r1, c1 in adjs if board[r1][c1] == 'M']
                if not ms:
                    board[r][c] = 'B'
                    q += [(r1, c1) for r1, c1 in adjs if board[r1][c1] == 'E']
                else:
                    board[r][c] = str(len(ms))    
        return board