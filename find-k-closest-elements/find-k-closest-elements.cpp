typedef pair<int, int> pi;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        for(auto ele:arr)
        {
            pq.push({abs(ele-x),ele});
        }
        vector<int>ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
        
        
    }
};