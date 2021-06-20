class Solution {
public:
    
    int n;
    int vis[51][51];
    vector<vector<int>>dir;
    
    bool isValid(int x, int y)
    {
        if(x>=0 and x<n and y>=0 and y<n)
            return true;
        return false;
    }
    
    bool check(int t, vector<vector<int>>& grid, int x, int y)
    {
        // cout<<x<<" "<<y<<" "<<grid[x][y]<<endl;
        if(x==n-1 and y==n-1 and grid[x][y]<=t)
            return true;
        
        vis[x][y]=1;
        bool op=false;
        for(int i=0; i<4; i++)
        {
            int a=x+dir[i][0] , b=y+dir[i][1];
            if(isValid(a,b) and !vis[a][b] and grid[a][b]<=t)
                op = op | check(t,grid,a,b);
        }
        
        return op;
    }
    
    int swimInWater(vector<vector<int>>& grid) 
    {
        n=grid.size();
        memset(vis,0,sizeof(vis));
        dir={{1,0} ,{0,1} ,{-1,0} ,{0,-1}};
        
        int lo=grid[0][0], hi=n*n-1;
        int ans=hi;
        
        while(lo<=hi)
        {
            memset(vis,0,sizeof(vis));
            int mid=lo+(hi-lo)/2;
            //cout<<mid<<endl;
            if(check(mid,grid,0,0))
            {
                ans=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        
        //For Debugging purpose
        // for(int i=lo; i<=hi; i++)
        // {
        //     memset(vis,0,sizeof(vis));
        //     int tmp=check(i,grid,0,0);
        //     if(tmp)
        //         ans=min(ans,i);
        //     cout<<i<<"-->"<<tmp<<endl;
        //     cout<<"----------------------"<<endl;
        // }
        
        return ans;
        
    }
};