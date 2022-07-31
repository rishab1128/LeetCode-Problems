class Solution {
public:
    int minimumOperations(vector<int>& arr) 
    {
        priority_queue<int,vector<int>,greater<>>pq;
        for(auto x: arr){
            if(x)
                pq.push(x);
        }
        
        int cnt = 0;
        while(pq.size())
        {
            int mini = pq.top();
            pq.pop();
            // cout<<mini<<endl;
            int sz = pq.size();
            priority_queue<int,vector<int>,greater<>>pq2;
            while(sz--)
            {
                int tp = pq.top();
                pq.pop();
                tp-=mini;
                // cout<<"Tp = "<<tp<<endl;
                if(tp)
                    pq2.push(tp);
            }
            pq = pq2;
            cnt++;
        }
        
        return cnt;
        
    }
};