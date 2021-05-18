const int mod=1e9+7;
class Solution {
public:
    long long dp[1001][1001];
    long long solve(int n, int k)
    {
        if(k==0 || k>n)
            return 0;
        if(n<=2)
            return 1;
        if(dp[n][k]!=-1)
            return dp[n][k];
        long long ans=0;
        ans=(ans+solve(n-1,k-1))%mod;
        ans=(ans+((n-1)*solve(n-1,k)))%mod;
        return dp[n][k]=ans;
    }
    int rearrangeSticks(int n, int k) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};