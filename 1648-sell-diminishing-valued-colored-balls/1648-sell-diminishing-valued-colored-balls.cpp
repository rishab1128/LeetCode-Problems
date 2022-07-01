using ll = long long;
const int mod = 1e9+7;
class Solution {
public:
    ll sum(ll high, ll low)
    {
        ll n = (high-low+1);
        ll ans = n*(high+low)/2;
        return ans;
    }
    
    int maxProfit(vector<int>& arr, int orders) 
    {
        int n = arr.size();
        
        map<ll,ll>mp;
        
        for(auto x: arr)
            mp[x]++;
        
        vector<pair<ll,ll>>brr;
        for(auto p : mp)
            brr.push_back(p);
        
        sort(brr.rbegin(),brr.rend());
        
        
        ll low = 1, high = brr[0].first;
        
        while(low<=high)
        {
            ll mid = low+(high-low)/2;
            
            ll ballsSold = orders;
            for(auto [ele,freq] : brr)
            {
                if(ele<=mid)
                    break;
                ballsSold -= (ele-mid)*freq;
                if(ballsSold<=0)
                    break;
            }
            if(ballsSold<=0)
                low=mid+1;
            else
                high=mid-1;
        }
        
        ll ans = 0;
        ll ballsSold = orders;
        for(auto [ele,freq] : brr)
        {
            if(ele<=low)
                break;
            ballsSold -= (ele-low)*freq;
            ans = (ans % mod + (freq % mod * sum(ele,low+1) % mod) % mod) % mod;
        }
        if(ballsSold)
            ans = (ans % mod + (low % mod * ballsSold % mod) % mod) % mod;
        
        return ans;
    }
};