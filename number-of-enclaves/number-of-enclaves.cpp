class Solution {
public:
    int n,m;
    vector<vector<int>>dir;
    void dfs(int x, int y, vector<vector<int>>& grid)
    {
        grid[x][y]=0;
        for(int i=0; i<4; i++)
        {
            int a=x+dir[i][0] , b=y+dir[i][1];
            if(a<n and a>=0 and b<m and b>=0 and grid[a][b])
                dfs(a,b,grid);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) 
    {
        dir={{1,0},{-1,0},{0,1},{0,-1}};
        n=grid.size() , m=grid[0].size();
        
        //First row / Top - boundary
        for(int j=0; j<m; j++)
        {
            if(grid[0][j])
                dfs(0,j,grid);
        }
        
        //Last row / Bottom - boundary
        for(int j=0; j<m; j++)
        {
            if(grid[n-1][j])
                dfs(n-1,j,grid);
        }
        
        
        //First col / Left-boundary
        for(int i=0; i<n; i++)
        {
            if(grid[i][0])
                dfs(i,0,grid);
        }
        
        //Last col / Right-boundary
        for(int i=0; i<n; i++)
        {
            if(grid[i][m-1])
                dfs(i,m-1,grid);
        }
        
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                ans+=grid[i][j];
        }
        
        return ans;
        
        
    }
};