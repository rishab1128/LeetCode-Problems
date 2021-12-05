class Solution {
public:
    //Similar to : CSES - Teleporters Path
    unordered_map<int,vector<int>>adj;
    unordered_map<int,int>indeg , outdeg;
    vector<int>ans;

    void dfs(int curr)
    {
        while(adj[curr].size())
        {
            int next=adj[curr].back();
            adj[curr].pop_back();
            dfs(next);
        }
        ans.push_back(curr);
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) 
    {
        
        int m=pairs.size();
        for(int i=0; i<m; i++)
        {
            int u=pairs[i][0] , v=pairs[i][1];
            adj[u].push_back(v);
            indeg[v]++;
            outdeg[u]++;
        }
        
        int start=pairs[0][0];
        for(int i=0; i<m; i++)
        {
            int u=pairs[i][0] , v=pairs[i][1];
            if(outdeg[u]-indeg[u]==1)
            {
                start=u;
                break;
            }
            if(outdeg[v]-indeg[v]==1)
            {
                start=v;
                break;
            }
        }

        dfs(start);    
        reverse(ans.begin(),ans.end());
        
        vector<vector<int>>res;
        for(int i=0; i<(int)ans.size()-1; i++)
            res.push_back({ans[i],ans[i+1]});
        
        return res;
        
    }
};