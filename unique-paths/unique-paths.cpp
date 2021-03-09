class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        long long dp[m][n];
        memset(dp,0,sizeof(dp));
        dp[m-1][n-1]=1;
        //Filling last row
        for(int j=n-2; j>=0; j--)
        {
            dp[m-1][j]=1;
        }
        //Filling last col
        for(int i=m-2; i>=0; i--)
        {
            dp[i][n-1]=1;
        }
        //Filling the rest of the table
        for(int i=m-2; i>=0; i--)
        {
            for(int j=n-2; j>=0; j--)
            {
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
        
    }
};