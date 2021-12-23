class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) 
    {
        vector<int>adj[n];
        vector<int>indeg(n,0);
        queue<int>q;
        for(int i=0; i<(int)pre.size(); i++)
        {
            int u=pre[i][1] , v=pre[i][0];
            adj[u].push_back(v);
            indeg[v]++;
        }
        for(int i=0; i<n; i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto child : adj[node])
            {
                indeg[child]--;
                if(indeg[child]==0)
                    q.push(child);
            }
        }
        if(ans.size()!=n)
            return {};
        
        return ans;
        
    }
};