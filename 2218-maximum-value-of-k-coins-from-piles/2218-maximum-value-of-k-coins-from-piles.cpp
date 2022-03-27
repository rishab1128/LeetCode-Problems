using ll = long long;
class Solution {
public:
    ll recur(vector<vector<ll>>&pref , ll idx, int k, vector<vector<ll>>&dp)
    {
        if(idx>=(int)pref.size())
            return 0;
        
        if(dp[idx][k]!=-1)
            return dp[idx][k];
        
        ll ans=0;
        for(int i=0; i<=min(k,(int)pref[idx].size()-1); i++)
        {
            ans=max(ans , pref[idx][i]+recur(pref,idx+1,k-i,dp));
        }
        return dp[idx][k]=ans;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        int n=piles.size();
        vector<vector<ll>>dp(n+1,vector<ll>(k+1,-1));
        vector<vector<ll>>pref;
        for(int i=0; i<n; i++)
        {
            int m=piles[i].size();
            vector<ll>tmp(m+1,0);
            tmp[1]=piles[i][0];
            for(int j=2; j<=m; j++)
                tmp[j]=tmp[j-1]+piles[i][j-1];
            pref.push_back(tmp);
        }
        
        /*for(auto v : pref)
        {
            for(auto ele : v)
                cout<<ele<<" ";
            cout<<endl;
        }*/
        
        ll ans = recur(pref , 0 , k , dp);
        return ans;
        
    }
};