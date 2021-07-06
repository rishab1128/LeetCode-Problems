class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int lo=0,hi=nums.size() -1;
        int ans=-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                break;
            }
            else if(nums[mid]>target)
                hi=mid-1;
            else
                lo=mid+1;
        }
        return ans;
        
    }
};