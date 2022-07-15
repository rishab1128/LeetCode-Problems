class Solution {
public:
    long long dp[501];
    const int mod = 1e9+7;
    using ll = long long;
    int countOrders(int n) 
    {
        if(n==1)
            return 1;
        if(dp[n])
            return dp[n];
        long long ans = ((ll)n % mod * (ll)(2*n-1) % mod * (ll)countOrders(n-1) % mod) % mod;
        return dp[n] = ans % mod;
    }
};