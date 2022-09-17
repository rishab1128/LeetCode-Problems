class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& arr1, vector<int>& arr2) 
    {
        multiset<int>st;
        for(auto &x: arr2)
            st.insert(x);
        
        int cnt = 0;
        for(int i=0; i<(int)arr1.size(); i++)
        {
            auto it = st.lower_bound(arr1[i]);
            if(it!=st.end())
            {
                cnt++;
                st.erase(it);
            }
        }
        
        return cnt;
        
    }
};