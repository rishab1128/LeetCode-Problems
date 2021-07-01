class Solution {
public:
    int n,m;
    int vis[101][101];
    int vis2[101][101];

    vector<vector<int>>dir;

    void dfs(vector<vector<int>>& mat , int i, int j , set<pair<int,int>>&coord)
    {
        vis[i][j]=1;
        coord.insert({i,j});
        for(int t=0; t<4; t++)
        {
            int x=i+dir[t][0] , y=j+dir[t][1];
            if(x<n and y<m and x>=0 and y>=0 and mat[x][y] and !vis[x][y])
                dfs(mat,x,y,coord);
        }
    }

    int solve(vector<vector<int>>& mat) 
    {
        memset(vis,0,sizeof(vis));
        dir={{1,0}, {-1,0} , {0,1} , {0,-1}};
        n=mat.size();
        if(n==0)
            return 0;
        m=mat[0].size();
        int sum=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==1 and !vis[i][j])
                {
                    set<pair<int,int>>coord;
                    memset(vis2,0,sizeof(vis2));
                    dfs(mat,i,j,coord);
                    sum+=coord.size()*4;
                    for(auto a: coord)
                    {
                        int i=a.first , j=a.second;
                        vis2[i][j]=1;
                        //cout<<"("<<i<<","<<j<<") ";
                        for(int t=0; t<4; t++)
                        {
                            int x=i+dir[t][0] , y=j+dir[t][1];
                            if(coord.find({x,y})!=coord.end() and vis2[x][y]==0)
                                sum-=2;
                        }
                        //cout<<sum<<endl;
                    }
                    //cout<<endl;
                }
            }
        }
        return sum;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        return solve(grid);
    }
};