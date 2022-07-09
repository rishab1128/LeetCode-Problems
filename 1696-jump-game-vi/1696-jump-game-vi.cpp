class Solution {
public:
    int maxResult(vector<int>& arr, int k) 
    {
        int n = arr.size();
        
        //Maintian a max-priority queue of size k
        priority_queue<pair<int,int>>pq;
        
        vector<int>dp(n);
        //dp[i] := max sum if we start from i
        
        
        dp[n-1]=arr[n-1];
        pq.push({dp[n-1],n-1});
        
        for(int i=n-2; i>=0; i--)
        {
            while(pq.size() and pq.top().second>i+k)
                pq.pop();
            
            auto [maxi,idx] = pq.top();
            dp[i] = arr[i]+maxi;
            pq.push({dp[i],i});
        }
        
        return dp[0];
    }
};