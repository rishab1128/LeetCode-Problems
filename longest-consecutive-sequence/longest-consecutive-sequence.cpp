class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int longestConsecutive(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int ct=1,maxi=1;
        if(nums.size()==0)
            return 0;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]-nums[i-1]==0)
                continue;
            if(nums[i]-nums[i-1]==1)
                ct++;
            else if(nums[i]-nums[i-1]>1)
                ct=1;
            maxi=max(maxi,ct);
        }
        return maxi;
    }
};