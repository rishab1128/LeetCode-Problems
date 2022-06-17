class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        if(n==1)
            return 0;
        vector<vector<bool>> vis(n,vector<bool>((1<<n),0));
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++)
        {
            q.push({i,(1<<i)});
            vis[i][(1<<i)]=1;
        }
        
        int ans = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto [node , mask] = q.front();
                q.pop();
                if(mask==(1<<n)-1)
                    return ans;
                for(auto neigh : graph[node])
                {
                    int newMask = mask|(1<<neigh);
                    if(!vis[neigh][newMask])
                    {
                        vis[neigh][newMask]=1;
                        q.push({neigh,newMask});
                    }
                }
            }
            ans++;
        }
        
        return 0;
        
    }
};