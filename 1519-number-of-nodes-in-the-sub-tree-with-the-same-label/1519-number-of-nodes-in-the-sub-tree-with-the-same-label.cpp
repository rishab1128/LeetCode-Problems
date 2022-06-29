class Solution {
public:
    
    vector<int>ans;
    vector<bool>vis;
    
    vector<int>dfs(int node, vector<vector<int>>&adj, string&s)
    {
        vis[node]=1;
        vector<int>freq(26,0);
        freq[s[node]-'a']++;
        for(auto child : adj[node])
        {
            if(!vis[child])
            {
                vector<int>childFreq = dfs(child,adj,s);
                for(int i=0; i<26; i++)
                    freq[i]+=childFreq[i];
            }
        }
        ans[node] = freq[s[node]-'a'];
        return freq;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {
        vis.resize(n,0);
        ans.resize(n);
        vector<vector<int>>adj(n);
        for(auto edge : edges)
        {
            int u = edge[0] , v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(0,adj,labels);
        
        return ans;
    }
};