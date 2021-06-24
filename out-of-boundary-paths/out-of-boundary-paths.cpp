class Solution {
public:
    
    int findPaths(int m, int n, int moves, int startRow, int startCol) 
    {
        int mod=1e9+7;
        if(moves==0)
            return 0;
        if(m==1 and n==1)
        {
            //We can take only 1 move so moves doesn't matter
            return 4;
        }
        
        long long dp[moves+1][m][n];
        memset(dp,0,sizeof(dp));

        //dp[t][i][j] ---> (i,j) se boundary main jane ke liye kitna tarika hai such that you have only t number of moves left

        //Base Case if moves==1
        if(m==1)
        {
            for(int j=0; j<n; j++)
            {
                if(j==0 or j==n-1)
                    dp[1][0][j]=3;
                else
                    dp[1][0][j]=2;
            }
        }

        else if(n==1)
        {
            for(int i=0; i<m; i++)
            {
                if(i==0 or i==m-1)
                    dp[1][i][0]=3;
                else
                    dp[1][i][0]=2;
            }
        }

        else
        {
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    //for corner cells
                    if((i==0 and j==0) || (i==m-1 and j==0) || (i==0 and j==n-1) || (i==m-1 and j==n-1))
                    {
                        dp[1][i][j]=2;
                    }
                    //for boundary cells
                    else if(i==0 or i==m-1)
                        dp[1][i][j]=1;

                    else if(j==0 or j==n-1)
                        dp[1][i][j]=1;
                }
            }
        }


        //Fill the rest of the dp table
        for(int t=2; t<=moves; t++)
        {
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(i-1>=0)
                        dp[t][i][j]+=dp[t-1][i-1][j];
                    if(i+1<m)
                        dp[t][i][j]+=dp[t-1][i+1][j];
                    if(j-1>=0)
                        dp[t][i][j]+=dp[t-1][i][j-1];
                    if(j+1<n)
                        dp[t][i][j]+=dp[t-1][i][j+1];
                    dp[t][i][j]%=mod;
                }
            }
        }

        // for(int t=1; t<=moves; t++)
        // {
        //     for(int i=0; i<m; i++)
        //     {
        //         for(int j=0; j<n; j++)
        //             cout<<dp[t][i][j]<<" ";
        //         cout<<endl;
        //     }
        //     cout<<endl;
        // }

        int ans=0;
        for(int t=1; t<=moves; t++)
            ans=(ans%mod+dp[t][startRow][startCol]%mod)%mod;
        //cout<<ans<<endl;
        
        return ans;
    }
};