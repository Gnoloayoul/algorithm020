//DFS
void dfs(char** grid, int gridSize, int gridColSize, int i, int j)
{
if(i >= gridSize || j >= gridColSize || i<0 || j<0)
return;
if(grid[i][j] == '0')
return;

grid[i][j] = '0';

dfs(grid, gridSize, gridColSize, i+1, j);
dfs(grid, gridSize, gridColSize, i, j+1);
dfs(grid, gridSize, gridColSize, i-1, j);
dfs(grid, gridSize, gridColSize, i, j-1);

return;
}

int numIslands(char** grid, int gridSize, int* gridColSize){

int num = 0;

for(int i=0; i<gridSize; ++i)
{
    for(int j=0; j<*gridColSize; ++j)
    {
        if(grid[i][j] == '1')
        {
            ++num;
            dfs(grid, gridSize, *gridColSize, i, j);
        }
            
    }
}
return num;
}

//BFS
void bfs(int x, int y, char** grid, int gridSize, int* gridColSize){
    if(grid[x][y]=='1') grid[x][y]='0';
    else return;
    if(x>0) bfs(x-1,y,grid,gridSize,gridColSize);
    if(y>0) bfs(x,y-1,grid,gridSize,gridColSize);
    if(x<gridSize-1) bfs(x+1,y,grid,gridSize,gridColSize);
    if(y<*gridColSize-1) bfs(x,y+1,grid,gridSize,gridColSize);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int cnt=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<*gridColSize;j++){
            if(grid[i][j]=='1'){
                cnt++;
                bfs(i,j,grid,gridSize,gridColSize);
            }
        }
    }
    return cnt;
}