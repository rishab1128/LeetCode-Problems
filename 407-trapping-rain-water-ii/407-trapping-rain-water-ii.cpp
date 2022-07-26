class Solution {
public:
    int trapRainWater(vector<vector<int>>&arr) 
    {
        int n = arr.size() , m = arr[0].size();
        priority_queue<vector<int> , vector<vector<int>> , greater<>>pq;
        bool vis[n][m];
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    pq.push({arr[i][j],i,j});
                    vis[i][j] = 1;
                }
            }
        }
        vector<vector<int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int ans = 0;
        int minBdHt = 0;
        while(!pq.empty())
        {
            vector<int>top = pq.top();
            pq.pop();
            int ht = top[0] , x = top[1] , y = top[2];
            minBdHt = max(minBdHt , ht);
            for(int i=0; i<4; i++)
            {
                int dx = x+dir[i][0] , dy = y+dir[i][1];
                if(dx>=0 and dx<n and dy>=0 and dy<m and !vis[dx][dy])
                {
                    pq.push({arr[dx][dy],dx,dy});
                    vis[dx][dy] = 1;
                    if(arr[dx][dy]<minBdHt)
                        ans+=minBdHt-arr[dx][dy];
                }
            }
        }
        return ans;
        
    }
};