class Solution {
public:
    int dp[105];
    int func(vector<int>& nums, int n, int idx)
    {
        if(idx>=n)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int op1=func(nums,n,idx+2)+nums[idx];
        int op2=func(nums,n,idx+1);
        return dp[idx]=max(op1,op2);
    }
    int rob(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        int ans=func(nums,n,0);
        return ans;
    }
};