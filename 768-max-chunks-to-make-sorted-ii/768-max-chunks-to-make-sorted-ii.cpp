class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        //Using Monotonic Stack
        //Each element in the stack represents the largest value in each chunk when the chunk cannot be partitioned to smaller ones
        int n = arr.size();
        stack<int>st;
        for(int i=0; i<n; i++)
        {
            int maxi = arr[i];
            while(st.size() and st.top()>arr[i])
                maxi = max(maxi,st.top()) , st.pop();
            st.push(maxi);
        }
        int ans = st.size();
        return ans;
        
        
    }
};