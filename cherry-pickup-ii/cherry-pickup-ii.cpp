class Solution {
public:
    int n,m;
    int dp[71][71][71];
    
    int func(vector<vector<int>>&grid , int row, int col1 , int col2)
    {
        if(row>=n or col1>=m or col1<0 or col2>=m or col2<0)
            return 0;
        
        if(dp[row][col1][col2]!=-1)
            return dp[row][col1][col2];
        
        int res=0;
        if(col1 != col2)
            res=grid[row][col1]+grid[row][col2];
        else
            res=grid[row][col1];
        
        int op1=res+func(grid,row+1,col1,col2);
        int op2=res+func(grid,row+1,col1,col2-1);
        int op3=res+func(grid,row+1,col1,col2+1);
        
        int op4=res+func(grid,row+1,col1-1,col2);
        int op5=res+func(grid,row+1,col1-1,col2-1);
        int op6=res+func(grid,row+1,col1-1,col2+1);
        
        int op7=res+func(grid,row+1,col1+1,col2);
        int op8=res+func(grid,row+1,col1+1,col2-1);
        int op9=res+func(grid,row+1,col1+1,col2+1);
        
        return dp[row][col1][col2]=max({op1,op2,op3,op4,op5,op6,op7,op8,op9});
    }
    
    int cherryPickup(vector<vector<int>>& grid) 
    {
        memset(dp,-1,sizeof(dp));
        n=grid.size(),m=grid[0].size();
        int ans=func(grid,0,0,m-1);
        return ans;
    }
};