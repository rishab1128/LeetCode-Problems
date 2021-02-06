typedef long long ll;
class Solution {
public:
    ll func(vector<int>a, int n)
    {
        ll curr_max=0,best_max=0,curr_min=0,best_min=0,ans=0;

        for(ll i=0; i<n; i++)
        {
            curr_max+=a[i];
            curr_min+=a[i];
            if(curr_max<0)
                curr_max=0;
            if(curr_min>0)
                curr_min=0;
            if(curr_max>best_max)
                best_max=curr_max;
            if(curr_min<best_min)
                best_min=curr_min;
        }

        ans=max(best_max,abs(best_min));
        return ans;
    }
    
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int n=nums.size();
        return func(nums,n);
    }
};