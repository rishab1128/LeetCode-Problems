class Solution {
public:
    vector<int> intersection(vector<vector<int>>& arr) 
    {
        int n = arr.size();
        unordered_map<int,int>mp;
        for(auto v: arr)
        {
            for(auto ele : v)
                mp[ele]++;
        }
        vector<int>ans;
        for(auto [ele, freq] : mp)
        {
            if(freq==n)
                ans.push_back(ele);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};