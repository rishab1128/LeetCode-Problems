class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
        unordered_map<int,int>mp;
        for(auto x: arr)
            mp[x]++;
        
        vector<pair<int,int>>v;
        for(auto x: mp)
            v.push_back({x.second,x.first});
        
        sort(v.begin(),v.end());
        
        int n=v.size() , i=0;
        for(i=0; i<n; i++)
        {
            if(v[i].first>k)
                break;
            k-=v[i].first;
        }
        
        return n-i;
    }
};