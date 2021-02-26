class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    int findUnsortedSubarray(vector<int>& nums) 
    {
        vector<int>tmp(nums.begin(),nums.end());
        sort(tmp.begin(),tmp.end());
        int left=INT_MAX, right=INT_MIN, flag=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]!=tmp[i])
            {
                flag=1;
                left=min(left,i);
                right=max(right,i);
            }
        }
        if(!flag)
            return 0;
        return right-left+1;
    }
};