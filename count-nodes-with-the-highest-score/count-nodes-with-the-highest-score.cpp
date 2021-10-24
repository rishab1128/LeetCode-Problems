#include<bits/stdc++.h>
using namespace std;
using ll=long long;

class Solution {
public:
    unordered_map<int,vector<int>>adj;

    ll dfs(int node , vector<ll>&dp)
    {
        ll ct=1;
        for(auto child : adj[node])
        {
            ct+=dfs(child , dp);
        }
        dp[node]=ct;
        return dp[node];
    }

    int countHighestScoreNodes(vector<int>& par)
    {
        adj.clear();
        int n=par.size();
        for(int i=1; i<n; i++)
        {
            int u=par[i],v=i;
            adj[u].push_back(v);
            //adj[v].push_back(u);
        }
        vector<ll>dp(n);
        dfs(0,dp);

        // for(auto x: dp)
        //     cout<<x<<" ";
        // cout<<endl;

        vector<ll>score(n);
        ll maxi=0;
        for(int i=0; i<n; i++)
        {
            if(i==0 and adj[i].size()==2)
            {
                int sub1=adj[i][0] , sub2=adj[i][1];
                score[i]=dp[sub1]*dp[sub2];
            }
            else if(i==0 and adj[i].size()==1)
            {
                int sub1=adj[i][0];
                score[i]=dp[sub1];
            }
            else if(i!=0 and adj[i].size()==2)
            {
                int sub1=adj[i][0],sub2=adj[i][1],parent=0;
                score[i]=dp[sub1]*dp[sub2]*(dp[parent]-dp[i]);
            }
            else if(i!=0 and adj[i].size()==1)
            {
                int sub1=adj[i][0],parent=0;
                score[i]=dp[sub1]*(dp[parent]-dp[i]);
            }
            if(adj[i].size()==0)
                score[i]=n-1;

            maxi=max(maxi,score[i]);
        }

        // for(auto x: score)
        //     cout<<x<<" ";
        // cout<<endl;

        ll ans=count(score.begin(),score.end(),maxi);

        return ans;


    }
};