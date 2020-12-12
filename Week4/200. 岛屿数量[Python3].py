class Solution:#DFS
    def numIslands(self, grid: List[List[str]]) -> int:
        def dfs(x, y):
            f[x][y] = 1
            if y+1 < w and grid[x][y+1] == '1' and f[x][y+1] == 0:
                f[x][y+1] = 1
                dfs(x, y+1)
            if x+1 < h and grid[x+1][y] == '1' and f[x+1][y] == 0:
                f[x+1][y] = 1
                dfs(x+1, y)
            if y-1 >= 0 and grid[x][y-1] == '1' and f[x][y-1] == 0:
                f[x][y-1] = 1
                dfs(x, y-1)
            if x-1 >= 0 and grid[x-1][y] == '1' and f[x-1][y] == 0:
                f[x-1][y] = 1
                dfs(x-1, y)
        
        if not grid:
            return 0
        
        h, w = len(grid), len(grid[0])
        f = [[0] * w for _ in range(h)]
        
        res = 0
        for i in range(h):
            for j in range(w):
                if grid[i][j] == '1' and f[i][j] == 0:
                    res += 1
                    dfs(i, j)
                    
        return res


        from collections import deque





class Solution:#BFS
    def numIslands(self, grid: List[List[str]]) -> int:
        def bfs(sr,sc):
            Queue=collections.deque([(sr,sc)])
            M,N=len(grid),len(grid[0])
            while Queue:
                r,c=Queue.popleft()
                for nr,nc in [(r+1,c),(r-1,c),(r,c-1),(r,c+1)]:
                    if  0<=nr<M and 0<=nc<N and grid[nr][nc]=="1":
                        grid[nr][nc]="0"
                        Queue.append((nr,nc))
        ans=0
        for r,row in enumerate(grid):
            for c in range(len(row)):
                if grid[r][c]=="1":
                    grid[r][c]="0"
                    bfs(r,c)
                    ans+=1
        return ans