class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& arr, vector<int>& per) 
    {
        map<int,int>mp;
        for(auto v :  arr)
        {
            int start = v[0] , end = v[1];
            mp[start]+=1;
            mp[end+1]-=1;
        }
        
        vector<pair<int,int>>pref;
        for(auto x : mp)
            pref.push_back(x);
        
        int m = pref.size();
        for(int i=1; i<m; i++)
            pref[i].second += pref[i-1].second;
        
        vector<int>days(m);
        for(int i=0; i<m; i++){
            // cout<<pref[i].first<<" "<<pref[i].second<<endl;
            days[i] = pref[i].first;
        }
                    
        int sz = per.size();
        vector<int>ans(sz,0);
        for(int i=0; i<sz; i++)
        {
            int idx = upper_bound(days.begin(),days.end(),per[i])-days.begin();
            idx--;
            ans[i] = idx>=0 ? pref[idx].second : 0;
        }
        
        return ans;
        
    }
};