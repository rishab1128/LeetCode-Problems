using ll = long long;
class Solution {
public:
    
    unordered_map<int,vector<int>>adj;
    vector<bool>vis;
    
    void dfs(int node , int&ct)
    {
        ct++;
        vis[node]=1;
        for(auto child : adj[node])
        {
            if(!vis[child])
                dfs(child,ct);
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        adj.clear();
        vis.resize(n,0);
        
        for(auto arr : edges)
        {
            int u = arr[0] , v = arr[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<ll>conn;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                int ct = 0;
                dfs(i,ct);
                conn.push_back(ct);
            }
        }
        
        int m = conn.size();
        
        vector<ll>suff(m);
        suff[m-1]=conn[m-1];
        for(int i=m-2; i>=0; i--)
            suff[i]=suff[i+1]+conn[i];
        
        ll ans = 0;
        for(int i=0; i<conn.size()-1; i++)
        {
            ans+=conn[i]*suff[i+1];
        }
        
        return ans;
    }
};