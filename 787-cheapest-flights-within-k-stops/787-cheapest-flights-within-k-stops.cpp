class Solution {
public:
    //Using Djisktra 
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        unordered_map<int, vector< pair<int,int> > > adj;
        for(int i=0; i<flights.size(); i++)
        {
            int u=flights[i][0] , v=flights[i][1] , w=flights[i][2];
            adj[u].push_back({v,w});
        }
        
        vector<int>dist(n,INT_MAX);
        priority_queue< vector<int> , vector<vector<int>> , greater<> >pq;
        pq.push({0,src,0});  //cost, node, no. of stops required to reach current node from it's parent
        
        while(!pq.empty())
        {
            auto v=pq.top();
            pq.pop();
            
            int cost=v[0] , curr=v[1] , stops=v[2];
            
            if(curr==dst)
                return cost;
            
            if(stops>k)
                continue;
            
            if(dist[curr]<stops) //dist[curr] is the no. of stops required to reach current node from some other parent
                continue;
            else
                dist[curr]=stops;
            
            for(auto [neighNode , neighCost] : adj[curr])
            {
                pq.push({neighCost+cost , neighNode , stops+1});
            }
        }
        
        return -1;
        
    }
};