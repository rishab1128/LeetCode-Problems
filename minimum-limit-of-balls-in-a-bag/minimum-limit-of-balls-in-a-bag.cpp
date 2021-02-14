using ll=long long;
class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    bool check(int mid, vector<int>& nums, int maxio)
    {
        for(int i=0; i<(int)nums.size(); i++)
        {
            maxio-=nums[i]/mid;
            if(nums[i]%mid==0)
                maxio++;
        }
        return maxio>=0;
    }
    
    int minimumSize(vector<int>& nums, int maxio) 
    {
        //Binary Search on Answer
        ll start=1,end=INT_MAX,mid=0,ans=0;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(!check(mid,nums,maxio))
                start=mid+1;
            else
            {
                end=mid-1;
                ans=mid;
            }
                
        }
        return ans;
    }
};