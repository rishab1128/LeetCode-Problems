class Solution {
public:
    using ll = long long;
    ll zeroFilledSubarray(vector<int>& arr) 
    {
        ll n = arr.size();
        ll ans = 0;
        for(int i=0; i<n; i++)
        {
            int j = i;
            ll cnt = 0;
            while(j<n and arr[j]==0)
            {
                j++;
                cnt++;
            }
            ans += cnt*(cnt+1)/2;
            i = j;
        }
        return ans;
        
    }
};