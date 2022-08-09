class Solution {
public:
    int longestConsecutive(vector<int>& arr) 
    {
        int n = arr.size();
        
        unordered_set<int>st;
        for(auto x: arr)
            st.insert(x);
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(!st.count(arr[i]-1))
            {
                int currEle = arr[i];
                int currLen = 1;
                while(st.count(currEle+1))
                {
                    currEle++;
                    currLen++;
                }
                ans = max(ans,currLen);
            }
        }
        
        return ans;
        
    }
};