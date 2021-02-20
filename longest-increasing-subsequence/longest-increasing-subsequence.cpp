class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    //O(N^2) soln
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        int lis[n],ans=1;
        lis[0]=1;
        for(int i=1; i<n; i++)
        {
            lis[i]=1;
            for(int j=0; j<i; j++)
            {
                if(nums[i]>nums[j])
                    lis[i]=max(lis[i],lis[j]+1);
            }
            ans=max(ans,lis[i]);
        }
        return ans;
    }
};