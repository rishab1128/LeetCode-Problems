class Solution {
public:
    bool check(vector<set<int>>&arr , int i , int j)
    {
        for(auto x: arr[i])
        {
            if(arr[j].find(x)!=arr[j].end())
                return true;
        }
        return false;
    }
    
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) 
    {
        if(source==target)
            return 0;
        
        int n=routes.size();
        map<int,set<int>>mp;
        vector<set<int>>arr(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<routes[i].size(); j++)
            {
                mp[routes[i][j]].insert(i);
                arr[i].insert(routes[i][j]);
            }
        }
        
        //Construct the graph with buses as nodes. Two buses share an edge if they have a common bus stop b/w them.
        
        vector<int>adj[n];
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(check(arr,i,j))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        //Perfome BFS on bus nodes
        
        queue<int>q;
        vector<int>vis(n,0);
        for(auto bus : mp[source]){
            q.push(bus);
            vis[bus]=1;
        }
            
        
        int ct=1;
        while(q.size()>0)
        {
            int sz=q.size();
            while(sz--)
            {
                int bus=q.front();
                q.pop();
                if(mp[target].find(bus)!=mp[target].end())
                {
                    return ct;
                }
                for(auto neigh : adj[bus])
                {
                    if(!vis[neigh])
                    {
                        q.push(neigh);
                        vis[neigh]=1;
                    }
                }
            }
            ct++;
        }
        
        return -1;
        
    }
};