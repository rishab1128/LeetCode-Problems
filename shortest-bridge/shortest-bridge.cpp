class Solution {
public:
    queue<pair<int,int>>q;
    int vis[101][101];
    int n,m;
    vector<vector<int>>delta;
    
    void dfs(vector<vector<int>>& arr , int x, int y)
    {
        vis[x][y]=1;
        q.push({x,y});
        for(int i=0; i<4; i++)
        {
            int dx=x+delta[i][0] , dy=y+delta[i][1];
            if(dx>=0 and dx<n and dy>=0 and dy<m and arr[dx][dy] and !vis[dx][dy])
                dfs(arr,dx,dy);
        }
    }
    
    int shortestBridge(vector<vector<int>>& arr) 
    {
        n=arr.size() , m=arr[0].size() ;
        memset(vis,0,sizeof(vis));
        delta={{1,0} ,{-1,0} ,{0,1} ,{0,-1}};
        
        
        bool found=false;
        for(int i=0; i<n; i++)
        {
            if(found)
                break;
            for(int j=0; j<m; j++)
            {
                if(arr[i][j])
                {
                    dfs(arr,i,j);
                    found=true;
                    break;
                }
            }
        }
        
        //Expand the island stored inthe queue to meet the other island using BFS
        int ans=0;
        while(q.size()>0)
        {
            int sz=q.size();
            while(sz--)
            {
                int a=q.front().first , b=q.front().second;
                q.pop();
                for(int i=0; i<4; i++)
                {
                    int x=a+delta[i][0] , y=b+delta[i][1];
                    if(x>=0 and x<n and y>=0 and y<m and !vis[x][y])
                    {
                        if(arr[x][y]==1)
                        {
                            return ans;
                        }
                        vis[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
            ans++;
        }
        
        return -1;
        
        
    }
};