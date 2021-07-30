class Solution {
public:
    bool find132pattern(vector<int>& arr) 
    {
        int n=arr.size();
        vector<int>mini(n); //mini[i] = min ele from [0,i]
        mini[0]=arr[0];
        for(int i=1; i<n; i++)
            mini[i]=min(mini[i-1],arr[i]);
        
        set<int>st;
        st.insert(arr[n-1]);
        for(int j=n-2; j>0; j--)
        {
            
            auto it=st.lower_bound(arr[j]);
            if(it!=st.begin())
            {
                it--;
                int k=*it;
                int i=mini[j-1];
                if(i<k and k<arr[j])
                    return true;
            }
            st.insert(arr[j]);
        }
        return false;
        
    }
};