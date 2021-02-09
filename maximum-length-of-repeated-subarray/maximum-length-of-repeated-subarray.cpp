class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) 
    {
        int n=A.size(),m=B.size();
        int dp[n+1][m+1];
        int ans=0;
        
        //Note that dp[i][j] contains length of longest common suffix of X[0..i-1] and Y[0..j-1] 
 
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                if(i==0||j==0)
                    dp[i][j]=0;
                else if(A[i-1]==B[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    ans=max(ans,dp[i][j]);
                }
                else
                    dp[i][j]=0;
                    
            }
        }
        
        return ans;
        
    }
};