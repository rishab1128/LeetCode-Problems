class Solution {
public:
    //Detect cycle in a directed graph using Topo Sort
    //Using Kahn's Algo for Topo Sort
    bool canFinish(int n, vector<vector<int>>& edges) 
    {
        vector<int>adj[n+1];
        vector<int>indegree(n+1,0);
        for(int i=0; i<edges.size(); i++)
        {
            int v=edges[i][0] , u=edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        //Kahn's Algo Starts
        queue<int>q;
        vector<int>order;
        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(q.size()>0)
        {
            int x=q.front();
            order.push_back(x);
            q.pop();
            for(auto child : adj[x])
            {
                indegree[child]--;
                if(indegree[child]==0)
                    q.push(child);
            }
        }
        
        return order.size()==n;
        
    }
};