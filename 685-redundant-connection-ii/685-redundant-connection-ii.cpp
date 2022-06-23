class Solution {
public:
    
    void dfs(int root , unordered_map<int,set<int>>&adj, vector<bool>&vis, int&ct)
    {
        ct++;
        vis[root]=1;
        for(auto node : adj[root])
        {
            if(!vis[node])
                dfs(node,adj,vis,ct);
        }
        return ; 
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) 
    {
        int n  = edges.size();
        unordered_map<int,set<int>>adj;
        vector<int>indeg(n+1,0);
        
        for(auto edge: edges)
        {
            int u = edge[0] , v = edge[1];
            adj[u].insert(v);
            indeg[v]++;
        }
        
        for(int i=n-1; i>=0; i--)
        {
            int u = edges[i][0] , v = edges[i][1];
            indeg[v]--;
            adj[u].erase(v);
            int root = -1;
            for(int j=1; j<=n; j++)
            {
                if(!indeg[j])
                {
                    root=j;
                    break;
                }
            }
            int ct = 0;
            vector<bool>vis(n+1,0);
            dfs(root,adj,vis,ct);
            if(ct==n)
                return {u,v};
            else
            {
                adj[u].insert(v);
                indeg[v]++;
            }
                
        }
        
        return {};
        
        
    }
};