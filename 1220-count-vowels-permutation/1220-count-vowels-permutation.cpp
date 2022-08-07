class Solution {
public:
    using ll = long long;
    const int mod = 1e9+7;
    ll recur(int n,int prev, vector<vector<ll>>&dp)
    {
        if(n==0)
            return 1;
        
        if(dp[n][prev])
            return dp[n][prev];
        
        ll a = recur(n-1,1,dp)%mod , e = recur(n-1,2,dp)%mod , i = recur(n-1,3,dp)%mod , o = recur(n-1,4,dp)%mod , u = recur(n-1,5,dp)%mod;
        ll ans = 0;
        
        if(prev==0)
            ans = (a+e+i+o+u)%mod;
        
        else if(prev==1)
            ans = e%mod;
        
        else if(prev==2)
            ans = (a+i)%mod;
        
        else if(prev==3)
            ans = (a+e+o+u)%mod;
        
        else if(prev==4)
            ans = (i+u)%mod;
        
        else
            ans = a%mod;
        
        return dp[n][prev] = ans%mod;
    }
    
    int countVowelPermutation(int n) 
    {
        vector<vector<ll>>dp(n+1,vector<ll>(6,0));
        int ans = recur(n,0,dp);
        return ans;
        
    }
};