class Solution {
public:
    //Iterative Approach
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int calculateMinimumHP(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size(),tmp=0;
        int dp[m][n];
        
        dp[m-1][n-1]=(grid[m-1][n-1]<=0)?abs(grid[m-1][n-1])+1:1;
        
        //Filling the last row
        for(int j=n-2; j>=0; j--)
        {
           tmp=dp[m-1][j+1]-grid[m-1][j];
            if(tmp>0)
                dp[m-1][j]=tmp;
            else
                dp[m-1][j]=1;
        }
        //Filling the last col
        for(int i=m-2; i>=0; i--)
        {
            tmp=dp[i+1][n-1]-grid[i][n-1];
            if(tmp>0)
                dp[i][n-1]=tmp;
            else
                dp[i][n-1]=1;
        }
        //Filling the rest of the table
        for(int i=m-2; i>=0; i--)
        {
            for(int j=n-2; j>=0; j--)
            {
                tmp=min(dp[i][j+1],dp[i+1][j])-grid[i][j];
                if(tmp>0)
                    dp[i][j]=tmp;
                else
                    dp[i][j]=1;
            }
        }
        // for(int i=0; i<n; i++)
        // // {
        // //     for(int j=0; j<m; j++)
        // //         cout<<dp[i][j]<<" ";
        // //     cout<<endl;
        // // }
        return dp[0][0];
    }
};