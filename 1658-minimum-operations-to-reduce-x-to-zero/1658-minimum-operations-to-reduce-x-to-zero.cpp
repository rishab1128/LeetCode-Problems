class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int n=nums.size();
        if(n==0)
            return 0;
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
        }
        if(sum==x)
            return n;
        if(sum<x)
            return -1;
        sum=sum-x;
        //find max.length sub-array with sum S (O(N)-->Using HashMap)
        int tot=0,len=0;
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++)
        {
            tot+=nums[i];
            if(tot==sum)
                len=i+1;
            if(mp.find(tot)==mp.end())
                mp[tot]=i;
            if(mp.find(tot-sum)!=mp.end())
            {
                if(len<i-mp[tot-sum])
                    len=i-mp[tot-sum];
            }
        }
        if(len>0)
            return n-len;
        return -1;
    }
};