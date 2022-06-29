class Solution {
public:
    
    map<int,int>mp;
    
    int dfs(int node, vector<vector<int>>&adj, string &s)
    {
        if(!adj[node].size())
            return 1;
        
        pair<int,int>tmp={-1,-1};
        for(auto child : adj[node])
        {
            int lenChild = dfs(child,adj,s);
            if(s[child]!=s[node])
            {
                if(lenChild>tmp.second)
                    tmp.second=lenChild;
                if(tmp.second>tmp.first)
                    swap(tmp.first,tmp.second);
            }
        }
        
        int max1 = 0 , max2 = 0;
        if(tmp.first!=-1)
        {
            max1 = tmp.first;
        }
        if(tmp.second!=-1)
        {
            max2 = tmp.second; 
        }
        
        mp[node] = max(mp[node] , max1+max2+1);
        
        return max1+1;
        
    }
    
    int longestPath(vector<int>& par, string s) 
    {
        int n = par.size();
        vector<vector<int>>adj(n);
        for(int i=1; i<n; i++){
            adj[par[i]].push_back(i);
            // adj[i].push_back(par[i]);
        }
            
        
        dfs(0,adj,s);
        
        int ans = 1;
        for(auto [node,len] : mp)
        {
            // cout<<node<<" "<<len<<endl;
            ans = max(ans,len);
        }
        
        return ans;
    }
};