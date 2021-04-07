class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) 
    {
        vector<int>ans(k,0);
        set<pair<int,int>>st;
        vector<pair<int,int>>arr;
        
        for(int i=0; i<logs.size(); i++)
            st.insert({logs[i][0],logs[i][1]});
        
        for(auto x: st)
            arr.push_back({x.first, x.second});
        
        for(auto x: arr)
            cout<<x.first<<" "<<x.second<<endl;
        
        int sz=1;
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i].first==arr[i-1].first)
                sz++;
            else
            {
                if(sz<=k)
                    ans[sz-1]++;
                sz=1;
            }
        }
        if(sz<=k)
            ans[sz-1]++;
        return ans;
        
    }
};