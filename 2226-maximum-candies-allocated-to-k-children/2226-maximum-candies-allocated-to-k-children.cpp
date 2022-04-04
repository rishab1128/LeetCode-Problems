using ll=long long;
class Solution {
public:
    bool check(vector<int>&arr, ll num, ll k)
    {
        ll cnt=0;
        for(auto x: arr){
            cnt+=(x/num);
        }
        return cnt>=k;
    }
    
    int maximumCandies(vector<int>& candies, ll k)
    {
        ll sum=0;
        for(auto x: candies)
            sum+=x;
        
        if(k>sum)
            return 0;
        
        ll low = 1 , high = *max_element(candies.begin() , candies.end());
        
        ll ans=0;
        while(low<=high)
        {
            ll mid = low+(high-low)/2;
            if(check(candies , mid, k))
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        
        return ans;

    }
};