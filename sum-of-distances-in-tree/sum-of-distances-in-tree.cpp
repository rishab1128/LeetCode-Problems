//Same Question as Tree Distances II of CSES
#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    
    unordered_map<int,vector<int>>adj;
    vector<pair<int,int>>dp;
    vector<int>ans;
    int n;

    //Re-Rooting DP ==> Very useful techq. ==> Refer Code&Code / Kartik Arora

    pair<int,int> dfs1(int node , int par)
    {
        int c_no=0, children=0, sum=0;
        for(auto child : adj[node])
        {
            if(child!=par)
            {
                auto p=dfs1(child , node);
                sum+=p.first+p.second;
                children+=p.second;
                c_no++;
            }
        }
        dp[node].first=sum+c_no;
        dp[node].second=children+c_no;
        return dp[node];
    }

    void dfs2(int node , int par)
    {
        int num_of_nodes_in_par=n-dp[node].second-1;
        if(par!=-1)
            ans[node]=(ans[par]-dp[node].first-(dp[node].second+1))+num_of_nodes_in_par+dp[node].first;
        else
            ans[node]=dp[node].first;

        for(auto child : adj[node])
        {
            if(child!=par)
                dfs2(child , node);
        }
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges)
    {
        n=N;
        dp.resize(n);
        ans.resize(n);
        adj.clear();
        for(auto arr: edges)
        {
            int u=arr[0],v=arr[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs1(0,-1);
        dfs2(0,-1);
        return ans;
    }
};