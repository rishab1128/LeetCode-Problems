
class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    
    bool canPartition(vector<int>& nums) 
    {
        int n=nums.size(), sum=0;
        if(n==1)
            return false;
        for(auto x: nums)
            sum+=x;
        if(sum%2)
            return false;
        int target=sum/2;
        vector<bool>dp(target+1,false);
        dp[0]=true;
        for(int i=0; i<n; i++)
        {
            for(int j=target; j>=nums[i]; j--)
                dp[j]=dp[j] | dp[j-nums[i]];
        }
        return dp[target];
    }
};