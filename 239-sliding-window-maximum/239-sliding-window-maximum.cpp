class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) 
    {
        int n = arr.size();
        deque<int>dq; //Montonically Decreasing DQ
        vector<int>ans;
        
        for(int i=0; i<k; i++)
        {
            while(dq.size() and arr[dq.back()]<=arr[i])
                dq.pop_back();
            dq.push_back(i);
        }
        
        for(int i=k; i<n; i++)
        {
            ans.push_back(arr[dq.front()]);
            
            while(dq.size() and i-dq.front()>=k)
                dq.pop_front();
            
            while(dq.size() and arr[dq.back()]<=arr[i])
                dq.pop_back();
            dq.push_back(i);
        }
        
        if(dq.size())
            ans.push_back(arr[dq.front()]);
        
        return ans;
        
    }
};