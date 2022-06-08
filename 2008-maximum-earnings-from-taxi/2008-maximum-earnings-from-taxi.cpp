using ll=long long;
bool cmp(const vector<int>&a , const vector<int>&b)
{
    if(a[0]==b[0])
        return a[1]-a[0]+a[2]>b[1]-b[0]+b[2];
    return a[0]<b[0];
}

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) 
    {
        int m = rides.size();
        sort(rides.begin(),rides.end(),cmp);
        vector<ll>tmp(m);
        for(int i=0; i<m; i++)
            tmp[i]=rides[i][0];
        
        vector<ll>dp(m);
        dp[m-1]=rides[m-1][1]-rides[m-1][0]+rides[m-1][2];
        ll ans = dp[m-1];
        for(int i=m-2; i>=0; i--)
        {
            ll start = rides[i][0] , end = rides[i][1] , tip = rides[i][2];
            ll fare = end-start+tip;
            ll idx = lower_bound(tmp.begin(),tmp.end(),end)-tmp.begin();
            if(idx==m)
                dp[i] = max(fare,dp[i+1]);
            else
                dp[i]=max(dp[i+1],dp[idx]+fare);
            
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};