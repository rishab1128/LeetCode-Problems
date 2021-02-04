class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int findLHS(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=0;
        map<int,int>mp;
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
        }
        for(auto x: mp)
        {
            int key=x.first;
            if(mp.find(key+1)!=mp.end())
                ans=max(ans,mp[key]+mp[key+1]);
        }
        return ans;
    }
};