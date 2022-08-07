class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& arr) 
    {
        unordered_set<int>st;
        for(auto x: arr)
            st.insert(x);
        
        vector<vector<int>>adj(n);
        for(auto edge: edges)
        {
            int u = edge[0] , v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool>vis(n,0);
        
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        int cnt = 1;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto neigh : adj[node])
            {
                if(!vis[neigh] and !st.count(neigh))
                {
                    cnt++;
                    vis[neigh] = 1;
                    q.push(neigh);
                }
            }
        }
        
        return cnt;
        
    }
};