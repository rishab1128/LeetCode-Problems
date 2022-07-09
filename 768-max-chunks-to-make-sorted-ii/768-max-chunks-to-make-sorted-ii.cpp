class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        vector<int>tmp = arr;
        sort(tmp.begin(),tmp.end());
        multiset<int>st;
        int j , ans = 0 , last = 0;
        for(auto x: arr)
        {
            st.insert(x);
            j = last;
            for(auto y : st)
            {
                if(y!=tmp[j])
                    break;
                j++;
            }
            if(j-last==st.size()){
                // vector<int>future(arr.begin()+j,arr.end());
                st.clear();
                last = j;
                ans++;
            }
        }
        
        return ans;
    }
};