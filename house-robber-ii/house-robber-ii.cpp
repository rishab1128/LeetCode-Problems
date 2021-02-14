class Solution {
public:
    int dp[105];
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
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
        if(n<=2)
            return *max_element(nums.begin(), nums.end());
        vector<int>nums1,nums2;
        for(int i=0; i<n-1; i++)
            nums1.push_back(nums[i]);
        for(int i=1; i<n; i++)
            nums2.push_back(nums[i]);
        
        int ans1=func(nums1,n-1,0);
        memset(dp,-1,sizeof(dp));
        int ans2=func(nums2,n-1,0);
        
        return max(ans1,ans2);
        
        
    }
};