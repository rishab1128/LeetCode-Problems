class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        long long dp[m][n];
        memset(dp,0,sizeof(dp));
        //Base Cases
        if(grid[0][0]||grid[m-1][n-1])
            return 0;
        dp[m-1][n-1]=1;
        //Filling last row
        for(int j=n-2; j>=0; j--)
        {
            if(!grid[m-1][j])
                dp[m-1][j]=1;
            else
                break;
        }
        //Filling last col
        for(int i=m-2; i>=0; i--)
        {
            if(!grid[i][n-1])
                dp[i][n-1]=1;
            else
                break;
        }
        //Filling the rest of the table
        for(int i=m-2; i>=0; i--)
        {
            for(int j=n-2; j>=0; j--)
            {
                if(!grid[i][j])
                    dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};