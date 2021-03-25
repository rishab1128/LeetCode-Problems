class Solution {
public:
    int maxUncrossedLines(vector<int>& s1, vector<int>& s2) 
    {
        int m=s1.size() , n=s2.size();
        int dp[m+1][n+1]; 
        
        for(int i=0; i<=m; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==0)
                    dp[0][j]=0; 
                else if(j==0)
                    dp[i][0]=0; 
                else if(i!=0 and j!=0)
                {
                    if(s1[i-1]==s2[j-1])
                        dp[i][j]=dp[i-1][j-1]+1;
                    else
                        dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        
        return dp[m][n];
        
    }
};