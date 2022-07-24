class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) 
    {
        set<int>st;
        int ans = 1;
        for(auto x: rolls)
        {
            st.insert(x);
            if(st.size()==k)
            {
                ans++;
                st.clear();
            }
        }
        return ans;
    }
};