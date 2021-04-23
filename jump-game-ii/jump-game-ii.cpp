class Solution {
public:
    //TC: O(n*k)
    //Using recursion and memoization
    int dp[1001];
    long long int func(vector<int>&nums, int idx)
    {
        if(idx>=(int)nums.size()-1)
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        long long int mini=INT_MAX;
        for(int i=1; i<=nums[idx]; i++)
        {
            mini=min(mini,1+func(nums,idx+i));
        }
        return dp[idx]=mini;
    }
    
    int jump(vector<int>& nums) 
    {
        if(nums[0]==0)
            return 0;
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return func(nums,0);
    }
};