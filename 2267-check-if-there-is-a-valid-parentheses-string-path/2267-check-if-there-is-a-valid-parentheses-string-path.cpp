class Solution {
public:
    int n , m;
    bool dp[105][105][105];
    bool dfs(vector<vector<char>>& grid , int x, int y, int net)
    {
        
        if(grid[x][y]=='(')
            net++;
        else
            net--;
        
        if(net<0 || net>(m+n)/2 || dp[x][y][net])
            return false;
        
        if(x==n-1 and y==m-1 and net==0)
            return true;
        
        
        dp[x][y][net] = 1;
        
        if(x+1<n and dfs(grid,x+1,y,net))
            return true;
        
        if(y+1<m and dfs(grid,x,y+1,net))
            return true;
        
        return false;
    }
    
    bool hasValidPath(vector<vector<char>>& grid) 
    {
        memset(dp,0,sizeof(dp));
        n = grid.size() , m = grid[0].size();
        bool ans = dfs(grid,0,0,0);
        return ans;
    }
};