class Solution {
public:
    int vis[51][51];
    int n,m;
    void dfs(vector<vector<int>>& grid , int i, int j , int&tmp)
    {
        vis[i][j]=1;
        tmp+=1;
        if(i+1<n and grid[i+1][j]==1 and vis[i+1][j]==0)
            dfs(grid,i+1,j,tmp);
        
        if(i-1>=0 and grid[i-1][j]==1 and vis[i-1][j]==0)
            dfs(grid,i-1,j,tmp);
        
        if(j+1<m and grid[i][j+1]==1 and vis[i][j+1]==0)
            dfs(grid,i,j+1,tmp);
        
        if(j-1>=0 and grid[i][j-1]==1 and vis[i][j-1]==0)
            dfs(grid,i,j-1,tmp);
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        memset(vis,0,sizeof(vis));
        n=grid.size() , m=grid[0].size(); 
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1 and vis[i][j]==0)
                {
                    int tmp=0;
                    dfs(grid,i,j,tmp);
                    ans=max(ans,tmp);
                }
            }
        }
        return ans;
        
    }
};