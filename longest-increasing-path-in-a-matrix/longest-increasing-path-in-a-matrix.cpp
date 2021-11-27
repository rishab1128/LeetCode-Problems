class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& arr)
    {
        int n=arr.size() , m=arr[0].size(); 
        map< pair<int,int> , vector<pair<int,int>> > adj;
        map< pair<int,int>,int>indeg;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                //up
                if(i-1>=0 and arr[i-1][j]>arr[i][j])
                    adj[{i,j}].push_back({i-1,j}) , indeg[{i-1,j}]++;
                //down
                if(i+1<n and arr[i+1][j]>arr[i][j])
                    adj[{i,j}].push_back({i+1,j}) , indeg[{i+1,j}]++;
                
                //left
                if(j-1>=0 and arr[i][j-1]>arr[i][j])
                    adj[{i,j}].push_back({i,j-1}) , indeg[{i,j-1}]++;
                
                //right
                if(j+1<m and arr[i][j+1]>arr[i][j])
                    adj[{i,j}].push_back({i,j+1}) , indeg[{i,j+1}]++;
            }
        }
        
        queue<pair<int,int>>q;
        map<pair<int,int> , int>dp;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(indeg[{i,j}]==0)
                {
                    q.push({i,j});
                    dp[{i,j}]=1;
                }
            }
        }
        
        int ans=1;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto node=q.front();
                q.pop();
                ans=max(ans,dp[node]);
                for(auto child : adj[node])
                {
                    dp[child]=max(dp[child],dp[node]+1);
                    indeg[child]--;
                    if(indeg[child]==0)
                        q.push(child);
                }
            }
        }
        
        return ans;
    
    }
};