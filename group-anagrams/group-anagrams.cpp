class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        int n=strs.size();
        vector<string>arr;
        arr=strs;
        for(int i=0; i<n; i++)
        {
            sort(arr[i].begin(),arr[i].end());
        }
        map<string,vector<string>>mp;
        for(int i=0; i<n; i++)
        {
            mp[arr[i]].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto x: mp)
        {
            vector<string>tmp;
            string key=x.first;
            for(auto s:mp[key])
                tmp.push_back(s);
            ans.push_back(tmp);
        }
        return ans;
        
    }
};