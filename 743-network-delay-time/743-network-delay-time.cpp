class Solution {
public:
    vector<pair<int,int>>adj[101];
    
    int djikstra(int n , int source)
    {
        vector<int>vis(n+1,0);
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        pq.push({0,source});
        dist[source]=0;
        while(!pq.empty())
        {
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(vis[node])
                continue;
            vis[node]=1;
            for(auto child : adj[node])
            {
                int childNode=child.first;
                int childDis=child.second;
                if(dis+childDis<dist[childNode])
                {
                    dist[childNode]=dis+childDis;
                    pq.push({dist[childNode] , childNode});
                }
            }
        }
        
        int maxi=INT_MIN;
        for(int i=1; i<=n; i++)
            maxi=max(maxi,dist[i]);
        
        if(maxi==INT_MAX)
            return -1;
        
        return maxi;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        for(int i=0; i<101; i++)adj[i].clear();
        
        for(int i=0; i<times.size(); i++)
        {
            int u=times[i][0] , v=times[i][1] , w=times[i][2];
            adj[u].push_back({v,w});
        }
        
        int ans=djikstra(n,k);
        return ans;
    }
};