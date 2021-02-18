class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int dp[10005];
    int func(int n) 
    {
        if(n==0)
            return 0;
        if(dp[n])
            return dp[n];
        int mini=n; // Using all 1's
        for(int i=1; i*i<=n; i++)
        {
            mini=min(mini,func(n-i*i)+1);
        }
        return dp[n]=mini;
    }
    
    int numSquares(int n)
    {
         if(n<4)
            return n;
        memset(dp,0,sizeof(dp));
        return func(n);
    }
};