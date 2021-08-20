class Solution {
public:
    int shortestPath(vector<vector<int>>& arr, int k) 
    {
        int m=arr.size() , n=arr[0].size();
        
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        int vis[m+1][n+1][m*n+1];
        memset(vis,0,sizeof(vis));
            
        q.push({{0,0},k});
        vis[0][0][k]=1;
        int ct=0;
        while(q.size()>0)
        {
            int sz=q.size();
            while(sz--)
            {
                int x=q.front().first.first , y=q.front().first.second , lvl=q.front().second;
                q.pop();
                
                if(x==m-1 and y==n-1)
                    return ct;
        
                for(int i=0; i<4; i++)
                {
                    int dx=x+dir[i][0] , dy=y+dir[i][1];
                    if(dx>=0 and dx<m and dy>=0 and dy<n)
                    {
                        if(arr[dx][dy] and lvl-1>=0 and !vis[dx][dy][lvl-1])
                        {
                            q.push({{dx,dy},lvl-1});
                            vis[dx][dy][lvl-1]=1;
                        }
                        else if(arr[dx][dy]==0 and !vis[dx][dy][lvl])
                        {
                            q.push({{dx,dy},lvl});
                            vis[dx][dy][lvl]=1;
                        }
                    }
                }
            }
            if(q.size()>0)
                ct++;
        }
        return -1;
        
    }
};