using ll = long long;
const int mod = 1e9+7;
class Solution {
public:
    
    ll recur(string &s,vector<ll>&vis,ll curr,ll idx,ll n,vector<vector<ll>>&dp)
    {
        if(idx==s.size())
            return 1;
        if(dp[curr][idx]!=-1)
            return dp[curr][idx];
        ll res=0;
        vis[curr]=true;
        if(s[idx]=='I'){
            for(ll i=curr+1;i<=n;i++)
                if(!vis[i])
                    res=(res+recur(s,vis,i,idx+1,n,dp))%mod;

        }else{
            for(ll i=curr-1;i>=0;i--)
                if(!vis[i])
                    res=(res+recur(s,vis,i,idx+1,n,dp))%mod;

        }
        vis[curr]=false;
        return dp[curr][idx]=res;
    }
    
    int numPermsDISequence(string s) {
        ll n = s.size();
        vector<vector<ll>>dp(n+1,vector<ll>(n+1,-1));
        vector<ll>vis(n+1,0);
        ll res=0;
        for(ll i=0;i<=n;i++)
            res=(res+recur(s,vis,i,0,n,dp))%mod;
        return res;
    }
};