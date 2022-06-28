class Solution {
public:
    
    vector<int>ans;
    vector<bool>vis;
    pair<int,int>tmp={-1,-1};
    
    void dfs(int node, int lvl, vector<vector<int>> &adj , vector<int>&arr, vector<pair<int,int>>mp) //value - > {node,level}
    {
        vis[node]=1;
        int lastLevel = -1;
        for(int i=1; i<=50; i++)
        {
            if(__gcd(i,arr[node])==1 and mp[i]!=tmp)
            {
                auto [par,level] = mp[i];
                if(level>lastLevel)
                {
                    ans[node]=par;
                    lastLevel=level;
                }
            }
        }
        
        mp[arr[node]] = {node,lvl};
        
        for(auto child : adj[node])
        {
            if(!vis[child])
                dfs(child,lvl+1,adj,arr,mp);
        }
    }
    
    vector<int> getCoprimes(vector<int>& arr, vector<vector<int>>& edges) 
    {
        int n = arr.size();
        vector<vector<int>> adj(n);
        ans.resize(n,-1);
        vis.resize(n,0);
        
        for(auto edge : edges)
        {
            int u = edge[0] , v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<pair<int,int>>mp(51,{-1,-1});
        
        dfs(0,0,adj,arr,mp);
        
        return ans;
    }
};