class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        map<int,int>mp;
        priority_queue<int>pq;
        for(auto x: arr)
            mp[x]++;
        
        for(auto [x,y]:mp)
        {
            pq.push(y);
        }
        
        int n=arr.size();
        int sz=0 , ans=0;
        while(sz<n/2)
        {
            sz+=pq.top() ;
            pq.pop() ;
            ans++;
        }
        return ans;
        
    }
};