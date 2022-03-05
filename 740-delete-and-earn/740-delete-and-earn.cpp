class Solution {
public:
    int dp[20005];
    map<int,int>mp;
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
        if(idx+1<n&&nums[idx+1]-nums[idx]>1)
        {
            int op1=func(nums,n,idx+1)+(nums[idx]*mp[nums[idx]]);
            int op2=func(nums,n,idx+2)+(nums[idx]*mp[nums[idx]]);
            int op3=func(nums,n,idx+1);
            dp[idx]=max({op1,op2,op3});
        }
        else
        {
            int op1=func(nums,n,idx+2)+(nums[idx]*mp[nums[idx]]);
            int op2=func(nums,n,idx+1);
            dp[idx]=max(op1,op2);
        }
        
        return dp[idx];
    }
    int deleteAndEarn(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        set<int>st;
        vector<int>v;
        for(auto x: nums)
        {
            mp[x]++;
            st.insert(x);
        }
        for(auto x: st)
            v.push_back(x);
        int n=v.size();
        int ans=func(v,n,0);
        return ans;
    }
};