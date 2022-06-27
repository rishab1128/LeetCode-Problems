class Solution {
public:
    int dp[100001];
    
    bool recur(int n)
    {
        if(n==0)
            return 0;
        
        if(dp[n]!=-1)
            return dp[n];
        
        for(int i=1; i*i<=n; i++)
        {
            if(!recur(n-i*i))
                return dp[n] = 1;
        }
        
        return dp[n] = 0;
    }
    
    bool winnerSquareGame(int n) 
    {
        memset(dp,-1,sizeof(dp));
        int ans = recur(n);
        return ans;
    }
};