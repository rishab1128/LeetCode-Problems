//TC : O(N*log(K))
//SC : O(N+K)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        if(k==nums.size())
            return nums;
        
        unordered_map<int,int>mp;
        for(auto x: nums)
            mp[x]++;
        
        auto cmp = [&mp](int x1, int x2){
            return mp[x1] > mp[x2];
        };
        
        priority_queue<int, vector<int> , decltype(cmp)>pq(cmp);
        
        for(auto [ele,freq]: mp)
        {
            pq.push(ele);
            if(pq.size()>k)
                pq.pop();
        }
        vector<int>ans;
        while(pq.size())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
        
    }
};