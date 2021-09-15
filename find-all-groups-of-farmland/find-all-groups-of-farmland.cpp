class Solution {
public:
    int x,y,n,m;
    int flag;
    void dfs(int i, int j, vector<vector<int>>& land)
    {
        land[i][j]=0;
        if(j+1<m and land[i][j+1]) //Right
            dfs(i,j+1,land);
        
        if(i+1<n and land[i+1][j]) //Down
            dfs(i+1,j,land);
        
        if(j-1>=0 and land[i][j-1])//Left
        {
            if(!flag){
                x=i;
                y=j;
                flag=1;
            }
            dfs(i,j-1,land);
        }
        if(i-1>=0 and land[i-1][j])//Up
            dfs(i-1,j,land);
        
        if(!flag){
            x=i;
            y=j;
            flag=1;
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) 
    {
        n=land.size() , m=land[0].size();
        vector<vector<int>>ans;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(land[i][j]==1)
                {
                    x=i,y=j,flag=0;
                    vector<int>tmp;
                    tmp={i,j};
                    dfs(i,j,land);
                    tmp.push_back(x);
                    tmp.push_back(y);
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};