class Solution {
public:
    vector<int> advantageCount(vector<int>& arr1, vector<int>& arr2)
    {
        multiset<int>st;
        for(auto x: arr1){
            st.insert(x);
        }
        
        int n=arr1.size();
        vector<int>ans(n,-1);
        for(int i=0; i<n; i++)
        {
            auto it=st.upper_bound(arr2[i]);
            if(it!=st.end())
            {
                ans[i]=(*it);
                st.erase(it);
            }
        }
        
        if(st.empty())
            return ans;
        
        auto it=st.begin();
        for(int i=0; i<n; i++)
        {
            if(ans[i]==-1)
            {
                ans[i]=(*it);
                it++;
            }
        }
        
        return ans;
    }
};