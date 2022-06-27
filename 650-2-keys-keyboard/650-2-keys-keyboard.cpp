class Solution {
public:
    
    int dp[1001];
    
    int recur(int n)
    {
       if(n==1)
           return 0;
        
        if(dp[n]!=-1)
            return dp[n];
        
        int ans = n;
        
        for(int i=1; i<=n-1; i++)
        {
            if(n%i==0)
            {
                int x1=i;
                int x2=n/i;
                ans = min(ans , recur(x1)+(x2-2)+2);
            }
        }
        
        return dp[n] = ans;
    }
    
    int minSteps(int n) 
    {
        memset(dp,-1,sizeof(dp));
        return recur(n);
    }
};