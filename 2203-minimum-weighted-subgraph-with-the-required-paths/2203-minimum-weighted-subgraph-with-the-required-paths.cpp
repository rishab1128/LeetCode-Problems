using ll=long long;
const ll ll_INF  = 0x3f3f3f3f3f3f3f3f;

class Solution {
public:
    vector<ll>dijkstra(int src , vector<vector<pair<ll,ll>>>&adj, int n)
    {
        vector<ll>dist(n,ll_INF);
        dist[src]=0;
        priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , greater<> > pq;
        pq.push({0,src});
        while(!pq.empty())
        {
            ll currNode=pq.top().second;
            ll currDist=pq.top().first;
            pq.pop();
            
            if(currDist>dist[currNode])
                continue;

            for(auto child : adj[currNode])
            {
                ll childNode=child.first;
                ll childDist=child.second;
                if(currDist+childDist<dist[childNode])
                {
                    dist[childNode]=currDist+childDist;
                    pq.push({dist[childNode],childNode});
                }
            }
        }

        return dist;
    }

    ll minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) 
    {
        vector<vector<pair<ll,ll>>>adj(n), revAdj(n);
        ll ans=ll_INF;

        for(auto edge : edges){
            int u=edge[0] , v=edge[1] , w=edge[2];
            adj[u].push_back({v,w});
            revAdj[v].push_back({u,w});
        }

        vector<ll>dist1 = dijkstra(src1,adj,n);
        vector<ll>dist2 = dijkstra(src2,adj,n);
        vector<ll>dist3 = dijkstra(dest,revAdj,n);

        for(int i=0; i<n; i++)
        {
            ll dis1 = dist1[i]; //src1 -> i
            ll dis2 = dist2[i]; //src2 -> i
            ll dis3 = dist3[i]; //i    -> dest
            if(dis1!=ll_INF and dis2!=ll_INF and dis3!=ll_INF){
                ans=min(ans,dis1+dis2+dis3);
            }
        }

        return ans!=ll_INF ? ans : -1;
    }
};