class Solution {
public:
    
    vector<int>ans;
    vector<bool>vis;
    
    void bfs(int node, int lvl, vector<vector<int>> &adj, vector<int>&arr) //value - > {node,level}
    {
        queue<tuple<int,int,vector<pair<int,int>>>>q;
        vector<pair<int,int>>mp(51,{-1,-1});
        pair<int,int>tmp = {-1,-1};
        q.push({node,lvl,mp});
        vis[node]=1;
        
        while(!q.empty())
        {
            auto [node,lvl,mp] = q.front();
            q.pop();
            int lastLevel = -1;
            for(int i=1; i<=50; i++)
            {
                if(__gcd(i,arr[node])==1 and mp[i] != tmp)
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
                if(!vis[child]){
                    q.push({child,lvl+1,mp});
                    vis[child]=1;
                }
            }
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
        
        bfs(0,0,adj,arr);
        
        return ans;
    }
};