class DSU:
    def __init__(self):
        self.par = list(range(100001))
        self.rnk = [0] * 100001
    def find(self, x):
        if self.par[x] != x:
            self.par[x] = self.find(self.par[x])
        return self.par[x]
    def union(self, x, y):
        xr, yr = self.find(x), self.find(y)
        if xr == yr:
            return False
        elif self.rnk[xr] < self.rnk[yr]:
            self.par[xr] = yr
        elif self.rnk[xr] > self.rnk[yr]:
            self.par[yr] = xr
        else:
            self.par[yr] = xr
            self.rnk[xr] += 1
        return True

class Solution:
    def solve(self, board: List[List[str]]) -> None:       
        def dfs(x, y):
            dirs = [[0,1],[1,0],[0,-1],[-1,0]]
            seen.add((x, y))
            for d in dirs:
                nx, ny = x + d[0], y + d[1]
                if 0 <= nx < m and 0 <= ny < n and board[nx][ny] == 'O' and (nx, ny) not in seen:
                    uf.union(x*n+y, nx*n+ny)
                    dfs(nx, ny)

        m = len(board)
        if m == 0:
            return
        n = len(board[0])

        uf = DSU()
        seen = set()
        d = collections.defaultdict(set)
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O' and (i, j) not in seen:
                    dfs(i, j)

        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O':
                    par = uf.find(i*n+j)
                    x, y = par//n, par%n
                    d[(x,y)].add((i,j))

        lst = []
        for key in d:
            good = True
            for pos in d[key]:
                x, y = pos
                if x == 0 or x == m-1 or y == 0 or y == n-1:
                    good = False
                    break
            if good:
                lst.append(d[key])

        for s in lst:
            for pos in s:
                x, y = pos
                board[x][y] = 'X'