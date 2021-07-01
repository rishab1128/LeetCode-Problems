class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int>pq;
        for(auto x: stones)
            pq.push(x);
        
        while(pq.size() > 1)
        {
            int t1=pq.top();
            pq.pop();
            int t2=pq.top();
            pq.pop();
            if(t1-t2>=0)
                pq.push(t1-t2);
        }
        return pq.top();
    }
};