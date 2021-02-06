class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    
    int singleNumber(vector<int>& nums) 
    {
        vector<int>freq(32,0);
        long long n=nums.size(),ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<32; j++)
            {
               if(nums[i]&(1<<j))
                   freq[j]++;
            }
        }
        // for(auto x: freq)
        //     cout<<x<<" ";
        // cout<<endl;
        for(int i=0; i<32; i++)
        {
            if(freq[i]%3==1)
                ans+=(1<<i);
        }
        return ans;
    }
};