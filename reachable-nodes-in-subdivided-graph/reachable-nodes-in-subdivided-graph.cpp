class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) 
    {
        vector<pair<int,int>>adj[n];
        for(int i=0; i<edges.size() ; i++)
        {
            int u=edges[i][0] , v=edges[i][1] , w=edges[i][2];
            adj[u].push_back({v,w+1});
            adj[v].push_back({u,w+1});
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int>dist(n,INT_MAX);
        
        pq.push({0,0}); //Dist,Node
        dist[0]=0;
        while(pq.size()>0)
        {
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto child : adj[node])
            {
                int childNode=child.first;
                int childDis=child.second;
                if(childDis+dis<dist[childNode])
                {
                    dist[childNode]=childDis+dis;
                    pq.push({dist[childNode],childNode});
                }
            }
        }
        
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            if(dist[i]<=maxMoves)
                cnt++;
        }
        
        for(auto e: edges)
        {
            int u=e[0] , v=e[1] , w=e[2];
            int a=dist[u]>=maxMoves ? 0 : min(maxMoves-dist[u],w);
            int b=dist[v]>=maxMoves ? 0 : min(maxMoves-dist[v] , w);
            cnt+=min(a+b,w);
        }
        
        return cnt;
        
    }
};