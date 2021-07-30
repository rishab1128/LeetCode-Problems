class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) 
    {
        //Using montonic queue (decreasing one)
        int n=T.size();
        deque<int>dq;
        vector<int>ans(n);
        ans[n-1]=0;
        dq.push_back(n-1);
        for(int i=n-2; i>=0; i--)
        {
            while(!dq.empty() and T[dq.back()]<=T[i])
                dq.pop_back();
            
            if(dq.empty())
                ans[i]=0;
            else
                ans[i]=dq.back()-i;
            
            dq.push_back(i);
        }
        return ans;
        
        
    }
};