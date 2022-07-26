class Solution {
public:
    
    void dfs(vector<vector<int>>&adj, vector<bool>&vis, int start, int end)
    {
        vis[start] = 1;
        for(auto child : adj[start])
        {
            if(!vis[child])
                dfs(adj,vis,child,end);
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) 
    {
        vector<vector<int>>adj(n);
        vector<bool>vis(n,0);
        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0] , v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(adj,vis,start,end);
        return vis[end]==1;
    }
};