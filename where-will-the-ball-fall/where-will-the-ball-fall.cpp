class Solution {
public:
    int n,m;
    void dfs(vector<vector<int>>& grid , int i, int j, int&col)
    {
        //cout<<i<<" "<<j<<endl;
        //Stuck b/w rod and the left wall
        if(j==0 and grid[i][j]==-1)
        {
            col=-1;
            return;
        }
        
        //Stuck b/w rod and the right wall
        if(j==m-1 and grid[i][j]==1)
        {
            col=-1;
            return;
        }
        
        //Stuck b/w two rods
        if(j+1<m and grid[i][j]==1 and grid[i][j+1]==-1)
        {
            col=-1;
            return;
        }
        
        //Stuck b/w two rods
        if(j-1>=0 and grid[i][j]==-1 and grid[i][j-1]==1)
        {
            col=-1;
            return;
        }
        
        if(i==n-1)
        {
            if(grid[i][j]==-1)
                col=j-1;
            else
                col=j+1;
            return;
        }
        
        if(i+1<n and j+1<m and grid[i][j]==1)
            dfs(grid,i+1,j+1,col);
        if(i+1<n and j-1>=0 and grid[i][j]==-1)
            dfs(grid,i+1,j-1,col); 
    }
    
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        n=grid.size() , m=grid[0].size();
        vector<int>ans(m,-1);
        for(int j=0; j<m; j++)
        {
            int col=j;
            dfs(grid,0,j,col);
            ans[j]=col;
            //break;
        }
        return ans;
        
    }
};