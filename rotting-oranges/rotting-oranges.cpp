class Solution {
public:
    const int dx[4]={-1,0,1,0};
    const int dy[4]={0,-1,0,1};
    
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        int tot=0,ct=0,days=0;
        queue<pair<int,int>>q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]!=0)
                    tot++;
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        while(!q.empty())
        {
            int sz=q.size();
            ct+=q.size();
            while(sz--)
            {
                int x=q.front().first, y=q.front().second;
                q.pop();
                for(int i=0; i<4; i++)
                {
                    int sx=x+dx[i] , sy=y+dy[i];
                    if(sx<0 || sy<0 || sx >=m || sy>=n || grid[sx][sy]==0 || grid[sx][sy]== 2)
                        continue;
                    grid[sx][sy]=2;
                    q.push({sx,sy});
                }
            }
            if(q.size()>0)
                days++;
        }
        
        if(tot==ct)
            return days;
        
        return -1;
        
        
    }
};