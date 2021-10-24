class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& rel, vector<int>& time)
    {
        vector<int>adj[n+1];
        vector<int>indeg(n+1,0);
        vector<int>dp(n+1,0);
        for(int i=0; i<(int)rel.size(); i++)
        {
            int u=rel[i][0] , v=rel[i][1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int>q;
        for(int i=1; i<=n; i++)
        {
            if(indeg[i]==0){
                q.push(i);
                dp[i]=time[i-1];
            }
        }
        int ans=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int node=q.front();
                q.pop();
                for(auto child : adj[node])
                {
                    indeg[child]--;
                    dp[child]=max(dp[child] , dp[node]+time[child-1]);
                    if(indeg[child]==0)
                        q.push(child);
                }
            }
        }
        
        for(int i=1; i<=n; i++)
            cout<<dp[i]<<" ";
        cout<<endl;
        
        
        return *max_element(dp.begin(),dp.end());
        
        
    }
};