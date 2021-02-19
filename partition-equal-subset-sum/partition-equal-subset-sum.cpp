class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    
    bool func(vector<int>& nums, int target, int idx, vector<vector<int>>&dp)
    {
        if(idx>=nums.size()||target<0)
            return false;
        if(target==0)
            return true;
        if(dp[target][idx]!=-1)
            return dp[target][idx];
        bool op1=func(nums,target-nums[idx],idx+1,dp);
        bool op2=func(nums,target,idx+1,dp);
        return dp[target][idx]=op1|op2;
    }
    
    bool canPartition(vector<int>& nums) 
    {
        int n=nums.size(), sum=0;
        for(auto x: nums)
            sum+=x;
        if(sum%2)
            return false;
        int target=sum/2;
        vector<vector<int>>dp(target+1,vector<int>(n+1,-1));
        return func(nums,target,0,dp);
    }
};