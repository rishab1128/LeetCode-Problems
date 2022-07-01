using ll = long long;
class Solution {
public:
    vector<vector<int>>hats;
    const int mod = 1e9+7;
    int n;
    int dp[41][(1<<10)+1];
    
    ll recur(ll idx, ll peopleMask)
    {
        if(peopleMask==pow(2,n)-1)
            return 1;
        
        if(idx>40)
            return 0;
        
        if(dp[idx][peopleMask]!=-1)
            return dp[idx][peopleMask];
        
        ll ans = recur(idx+1,peopleMask); //Don't wear this hat
        for(auto person : hats[idx])
        {
            ll num = (1<<person);
            if(peopleMask&num) // person is already taken / person has already a hat with him
                continue;
            ans += recur(idx+1,peopleMask+num);
            ans %= mod;
        }
        return dp[idx][peopleMask] = ans;
    }
    
    int numberWays(vector<vector<int>>& arr) 
    {
        n  = arr.size();
        hats.resize(41);
        memset(dp,-1,sizeof(dp));
        
        //hats[i] -> stores all the people who can wear hat i
        
        for(int i=0; i<n; i++)
        {
            for(auto hat : arr[i])
                hats[hat].push_back(i);
        }
        
         
        ll ans = recur(1,0);
        return ans;
        
    }
};