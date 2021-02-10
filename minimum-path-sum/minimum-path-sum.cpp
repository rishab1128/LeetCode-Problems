class Solution {
public:
    //Iterative Approach
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        int dp[m][n];
        
        dp[m-1][n-1]=grid[m-1][n-1];
        
        //Filling the last row
        for(int j=n-2; j>=0; j--)
        {
            dp[m-1][j]=dp[m-1][j+1]+grid[m-1][j];
        }
        //Filling the last col
        for(int i=m-2; i>=0; i--)
        {
            dp[i][n-1]=dp[i+1][n-1]+grid[i][n-1];
        }
        //Filling the rest of the table
        for(int i=m-2; i>=0; i--)
        {
            for(int j=n-2; j>=0; j--)
            {
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])+grid[i][j];
            }
        }
        return dp[0][0];
    }
};