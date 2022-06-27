class Solution {
public:
    long long getDescentPeriods(vector<int>& arr) 
    {
        using ll =long long;
        int n = arr.size();
        vector<ll>dp(n,0);
        dp[0]=1;
        ll ans = 1;
        for(int i=1; i<n; i++)
        {
            if(arr[i-1]-arr[i]==1)
                dp[i]=dp[i-1]+1;
            else
                dp[i]=1;
            ans += dp[i];
        }
        return ans;
        
    }
};