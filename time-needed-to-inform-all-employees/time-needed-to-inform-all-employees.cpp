const int N=100001;
class Solution {
public:
    //Objective : Find out the max-path sum froom root to leaf in the tree
    vector<int>adj[N];
    int dfs(int headID , vector<int>&info)
    {
        
        if(adj[headID].size()==0)
            return 0;
        int maxi_time=0;
        for(auto child : adj[headID])
            maxi_time=max(maxi_time,dfs(child,info));
        
        return info[headID]+maxi_time;
        
    }
    
    int numOfMinutes(int n, int headID, vector<int>& man, vector<int>& info) 
    {
        
        for(int i=0; i<N; i++)adj[i].clear();
        for(int i=0; i<n; i++)
        {
            int u=man[i] , v = i;
            if(u!=-1)
                adj[u].push_back(v); //u->v "u is the manager of v"
        }
        
        return dfs(headID , info);
    }
};