class RangeFreqQuery {
private : unordered_map<int,vector<int>>mp;
public:
    RangeFreqQuery(vector<int>& arr) 
    {
        int n=arr.size();
        for(int i=0; i<n; i++)
        {
            int val=arr[i];
            mp[val].push_back(i);
        }
    }
    
    int query(int left, int right, int val) 
    {
        int lt=lower_bound(mp[val].begin() , mp[val].end() , left)-mp[val].begin();
        int rt=upper_bound(mp[val].begin() , mp[val].end() , right)-mp[val].begin();
        
        int ans=rt-lt;
        return ans;
        
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */