const int INF = 1e7;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& arr) 
    {
        int n=arr.size() , m=arr[0].size();
        queue<vector<int>>q;
        vector<vector<int>>dp(n,vector<int>(m,INF));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!arr[i][j])
                    q.push({i,j,0});
            }
        }
        while(!q.empty())
        {
            auto vec = q.front();
            q.pop();
            int i = vec[0] , j = vec[1], dist = vec[2];
            dp[i][j] = min(dist,dp[i][j]);
            if(i-1>=0)
            {
                if(arr[i-1][j] and dp[i-1][j]==INF)
                    q.push({i-1,j,dist+1});
                else if(!arr[i-1][j] and dp[i-1][j]==INF)
                    q.push({i-1,j,0});
            }
            if(j-1>=0)
            {
                if(arr[i][j-1] and dp[i][j-1]==INF)
                    q.push({i,j-1,dist+1});
                else if(!arr[i][j-1] and dp[i][j-1]==INF)
                    q.push({i,j-1,0});
            }
            if(i+1<n)
            {
                if(arr[i+1][j] and dp[i+1][j]==INF)
                    q.push({i+1,j,dist+1});
                else if(!arr[i+1][j] and dp[i+1][j]==INF)
                    q.push({i+1,j,0});
            }
            if(j+1<m)
            {
                if(arr[i][j+1] and dp[i][j+1]==INF)
                    q.push({i,j+1,dist+1});
                else if(!arr[i][j+1] and dp[i][j+1]==INF)
                    q.push({i,j+1,0});
            }
        }
        
        return dp;
    }
};