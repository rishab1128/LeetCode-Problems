class Solution {
public:
    
    string frequencySort(string s) 
    {
        unordered_map<char,int>mp;
        for(auto x: s)
            mp[x]++;
        vector<pair<int,char>>arr;
        for(auto x: mp)
            arr.push_back({x.second,x.first});
        
        sort(arr.rbegin(),arr.rend());
        string ans="";
        for(auto x: arr)
            ans+=string(x.first,x.second);
        
        return ans;
    }
};