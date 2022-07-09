class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        vector<int>tmp = arr;
        sort(tmp.begin(),tmp.end());
        int j;
        multiset<int>st;
        int ans = 0;
        for(auto x: arr)
        {
            st.insert(x);
            j = 0;
            for(auto y : st)
            {
                if(y!=tmp[j])
                    break;
                j++;
            }
            if(j==st.size()){
                vector<int>future(arr.begin()+j,arr.end());
                return 1+maxChunksToSorted(future);
            }
        }
        
        return 0;
    }
};