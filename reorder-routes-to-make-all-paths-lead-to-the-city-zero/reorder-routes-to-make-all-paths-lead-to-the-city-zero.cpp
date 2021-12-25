class Solution {
public:
    int minReorder(int n, vector<vector<int>>& arr) 
    {
        unordered_map<int,vector<int>>adj;
        map<pair<int,int>,int>mp;
        vector<int>vis(n,0);
        
        for(int i=0; i<n-1; i++)
        {
            int u=arr[i][0] , v=arr[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            mp[{u,v}]=1;
        }
        
        queue<int>q;
        q.push(0);
        vis[0]=1;
        int count=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto neigh : adj[node])
            {
                if(!vis[neigh])
                {
                    vis[neigh]=1;
                    if(mp.find({node,neigh})!=mp.end())
                        count++;
                    q.push(neigh);
                }
            }
        }
        return count;
        
    }
};