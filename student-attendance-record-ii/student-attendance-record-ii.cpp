const long long mod=1000000007;
class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int dp[100005][2][3];
    int func(int n, int totalA, int contL)
    {
        if(n==0)
            return 1;
        if(dp[n][totalA][contL])
            return dp[n][totalA][contL];
        int res=0;
        if(totalA==0)
        {
            res+=func(n-1,totalA+1,0); //Add 'A'
            res%=mod;
        }
        if(contL<2)
        {
            res+=func(n-1,totalA,contL+1); //Add 'L'
            res%=mod;
        }
        res+=func(n-1,totalA,0);
        res%=mod;
        return dp[n][totalA][contL]=res;
            
    }
    int checkRecord(int n) 
    {
        memset(dp,0,sizeof(dp));
        return func(n,0,0);
    }
};