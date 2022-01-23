class Solution {
public:
    vector<int> findLonely(vector<int>& arr) 
    {
        unordered_map<int,int>mp;
        vector<int>ans;
        
        for(auto x: arr)
            mp[x]++;
        
        for(auto x: arr)
        {
            if(mp[x]==1 and mp[x-1]==0 and mp[x+1]==0)
                ans.push_back(x);
        }
        
        return ans;
        
    }
};