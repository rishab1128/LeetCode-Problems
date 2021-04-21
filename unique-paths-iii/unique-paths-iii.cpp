class Solution {
public:
    int n,m;
    int vis[21][21];
    
    int dfs(vector<vector<int>>&grid , int x, int y, int tot)
    {
        if(x<0 || x>=n || y<0 || y>=m || grid[x][y]==-1 || vis[x][y]==1)
            return 0;
        if(grid[x][y]==2 and tot==0)
            return 1;
        vis[x][y]=1;
        int paths=dfs(grid,x-1,y,tot-1)+dfs(grid,x+1,y,tot-1)+dfs(grid,x,y-1,tot-1)+dfs(grid,x,y+1,tot-1);
        vis[x][y]=0;
        return paths;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int sx, sy , tot=1;
        n=grid.size() , m=grid[0].size();
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    sx=i;
                    sy=j;
                }
                else if(grid[i][j]==0)
                    tot++;
            }
        }
        return dfs(grid,sx,sy,tot);
        
    }
};