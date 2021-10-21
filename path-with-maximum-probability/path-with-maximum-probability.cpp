class Solution {
public:
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        vector<pair<int,double>>adj[n];
        
        for(int i=0; i<edges.size(); i++)
        {
            int u=edges[i][0] , v=edges[i][1];
            double w=succProb[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<double>dist(n,(double)0.0);
        dist[start]=1.0;
        priority_queue<pair<double,int>>pq;
        pq.push({(double)1.0,start});
        while(!pq.empty())
        {
            double dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto child : adj[node])
            {
                double childDis=child.second;
                int childNode=child.first;
                if(childDis*dis>dist[childNode])
                {
                    dist[childNode]=childDis*dis;
                    pq.push({dist[childNode], childNode});
                }
            }
        }
        
        // for(auto x: dist)
        //     cout<<x<<" ";
        // cout<<endl;
        
        
        
        return dist[end];
        
        
        
        
        
    }
};