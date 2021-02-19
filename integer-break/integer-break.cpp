class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int integerBreak(int n) 
    {
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        for(int i=2; i<=n; i++)
        {
            dp[i]=1;
            for(int j=1; j<i; j++)
                dp[i]=max({dp[i],dp[i-j]*j,(i-j)*j});
        }
        return dp[n];
    }
};