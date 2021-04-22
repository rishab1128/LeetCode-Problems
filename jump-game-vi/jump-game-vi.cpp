class Solution {
public:
    int maxResult(vector<int>& nums, int k) 
    {
        int n=nums.size();
        priority_queue<pair<int,int>>pq;
        int dp[n]; //dp[i] -->max.score we can get if we go from idx 'i' to idx 'n-1'
        dp[n-1]=nums[n-1];
        pq.push({dp[n-1],n-1});
        for(int i=n-2; i>=0; i--)
        {
            dp[i]=nums[i];
            while(pq.size()>0  and pq.top().second>i+k)
            {
                pq.pop();
            }
            dp[i]+=pq.top().first;
            pq.push({dp[i],i});
        }
        return dp[0];
        
    }
};