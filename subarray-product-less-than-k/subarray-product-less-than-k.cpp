using ll=long long;
class Solution {
public:
    //Hint  : For each j, let opt(j) be the smallest i so that nums[i] * nums[i+1] * ... * nums[j] is less than k. opt is an increasing function,  so we can use a sliding window.
    int numSubarrayProductLessThanK(vector<int>& arr, int k) 
    {
        if(k<=1)
            return 0;
        int n=arr.size();    
        vector<int>opt(n,-1);
        ll prod=1,left=0;
        for(int right=0; right<n; right++)
        {
            prod*=arr[right];
            while(prod>=k and left<right)
            {
                prod/=arr[left];
                left++;
            }
            opt[right]=left;
        }
        int ans=0;
        for(int i=0; i<n; i++)
        {
            //cout<<opt[i]<<" ";
            if(opt[i]!=-1)
                ans+=(i-opt[i]+1);
        }
        return ans;
        
    }
};