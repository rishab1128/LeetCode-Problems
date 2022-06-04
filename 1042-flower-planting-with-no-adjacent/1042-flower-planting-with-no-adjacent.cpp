class Solution {
public:
    unordered_map<int,vector<int>>adj;
    vector<int>color;
    
    void bfs(int node)
    {
        queue<int>q;
        q.push(node);
        color[node]=1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop(); 
            for(auto neigh : adj[node])
            {
                // cout<<node<<" "<<neigh<<" "<<color<<endl;
                if(color[neigh]==-1)
                {
                    color[neigh]=max(1,(color[node]+1)%5);
                    q.push(neigh);
                }
                else if(color[neigh]==color[node])
                {
                    color[neigh]=max(1,(color[node]+1)%5);
                }
            }
        }
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) 
    {
        color.resize(n,-1);
        adj.clear();
        
        for(auto arr: paths)
        {
            int u = arr[0] , v = arr[1];
            u-- , v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0; i<n; i++)
        {
            if(color[i]==-1)
                bfs(i);
        }
        
        return color;
    }
};