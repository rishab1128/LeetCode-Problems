class Solution {
public:
    vector<int>rec;
    int ans;
    void dfs(int node, int par , vector<int>&edges, vector<int>&vis)
    {
        int u = node, v = edges[node]; //u->v
        vis[u] = 1;
        rec[u] = rec[par]+1;
        if(v!=-1)
        {
            if(vis[v])
            {
                if(rec[v])
                    ans = max(ans,rec[u]-rec[v]+1);
                rec[u] = 0;
                return;
            }
            else
                dfs(v,u,edges,vis);
        }
        rec[u] = 0;
        return;
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>vis(n,0);
        rec.resize(n,0);
        ans = -1;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
                dfs(i,i,edges,vis);  
        }
        return ans;
    }
};