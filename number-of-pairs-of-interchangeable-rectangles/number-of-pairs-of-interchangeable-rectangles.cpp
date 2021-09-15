using ll = long long;
class Solution {
public:
    ll interchangeableRectangles(vector<vector<int>>& rect) 
    {
        int n=rect.size();
        map<string,ll>mp;
        for(int i=0; i<n; i++)
        {
            int x=rect[i][0],y=rect[i][1];
            int gcd=__gcd(x,y);
            x/=gcd;
            y/=gcd;
            string t=to_string(x)+'/'+to_string(y);
            mp[t]++;
        }
        ll ans=0;
        for(auto x: mp)
        {
            string key=x.first;
            ll n=mp[key];
            ans+=(n*(n-1)/2);
        }
        return ans;
        
    }
};