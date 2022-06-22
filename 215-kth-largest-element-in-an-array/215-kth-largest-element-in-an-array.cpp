class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) 
    {
        priority_queue<int>pq;
        for(auto x: arr)
            pq.push(x);
        
        int ans = -1;
        while(k>0)
        {
            ans = pq.top();
            pq.pop();
            k--;
        }
        
        return ans;
        
    }
};