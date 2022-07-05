class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int>indeg(n,0);
        vector<vector<int>>adj(n);
        for(int i=0; i<n; i++)
        {
            int v = i;
            for(auto u : graph[i])
            {
                adj[u].push_back(v);
                indeg[v]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; i++)
        {
            if(!indeg[i])
                q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto child : adj[node])
            {
                indeg[child]--;
                if(!indeg[child])
                    q.push(child);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};