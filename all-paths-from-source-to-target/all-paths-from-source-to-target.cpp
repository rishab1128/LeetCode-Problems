#include<bits/stdc++.h>
using namespace std;

auto x = []() {
    ios::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


class Solution {
public:
    
    void dfs(int start, int end, vector<vector<int>>&adj, vector<int>tmp, vector<vector<int>>&ans )
    {
        tmp.push_back(start);
        if(start==end)
        {
            ans.push_back(tmp);
            return;
        }
        for(auto x: adj[start])
            dfs(x,end,adj,tmp,ans);
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>&adj) 
    {
        vector<vector<int>>ans;
        vector<int>tmp;
        int n=adj.size();
        if(n==0)
            return ans;
        dfs(0,n-1,adj,tmp,ans);
        return ans;
    }
};


