class Solution {
public:
    int longestConsecutive(vector<int>& arr) 
    {
        unordered_set<int>st;
        for(auto x: arr)
            st.insert(x);
        
        int ans = 0;
        for(auto ele : st)
        {
            if(!st.count(ele-1))
            {
                int currEle = ele;
                int currLen  = 1;
                while(st.count(currEle+1)){
                    currEle++;
                    currLen++;
                }
                ans = max(ans,currLen);
            }
        }
        
        return ans;
        
    }
};