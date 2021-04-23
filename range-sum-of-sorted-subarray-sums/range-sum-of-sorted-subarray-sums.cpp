class Solution {
public:
    //Using PQ
    //Refer : https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/discuss/730511/C%2B%2B-priority_queue-solution
    int rangeSum(vector<int>& nums, int n, int left, int right) 
    {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(int i=0; i<n; i++)
            pq.push({nums[i],i+1});
        
        int ans=0,mod=1'000'000'007;
        for(int i=1; i<=right; i++)
        {
            auto p=pq.top();
            pq.pop();
            int idx=p.second;
            if(i>=left)
            {
                ans=(ans+p.first)%mod;
            }
            if(idx<n)
            {
                p.first+=nums[idx];
                p.second++;
                pq.push(p);
            }
        }
        return ans;
        
    }
};