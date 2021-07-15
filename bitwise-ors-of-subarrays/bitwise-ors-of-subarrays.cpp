class Solution {
public:
    //Refer  : https://leetcode.com/problems/bitwise-ors-of-subarrays/discuss/165859/C%2B%2B-O(kN)-solution
    //Main - idea : Basically, the idea is to brute force all the possibilities. Only when add to result set, removing the dups to make the insert quick  .
    
    //Tip - Do a dry run for better understanding
    
    int subarrayBitwiseORs(vector<int>& arr) 
    {
        set<int>st;
        set<int>t;
        for(auto i: arr)
        {
            set<int>r;
            r.insert(i);
            for(auto j : t)r.insert(i|j);
            t=r;
            for(auto k:t)st.insert(k);
        }
        return st.size();
    }
};