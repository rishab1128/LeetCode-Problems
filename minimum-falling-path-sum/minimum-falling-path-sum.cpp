class Solution {
public:
    
    int func(vector<vector<int>>& arr , int row, int col , vector<vector<int>>&dp)
    {
        if(row >=arr.size() or row<0 or col >=arr.size() or col<0)
            return INT_MAX;
        if(row==arr.size()-1 and col <=arr.size()-1)
            return arr[row][col];
        if(dp[row][col]!=INT_MAX)
            return dp[row][col];
        
        int op1,op2,op3;
        op1=op2=op3=INT_MAX;
        
        if(func(arr,row+1,col,dp)!=INT_MAX)
            op1=arr[row][col]+func(arr,row+1,col,dp);
        
        if(func(arr,row+1,col+1,dp)!=INT_MAX)
            op2=arr[row][col]+func(arr,row+1,col+1,dp);
        
        if(func(arr,row+1,col-1,dp)!=INT_MAX)
            op3=arr[row][col]+func(arr,row+1,col-1,dp);
        
        return dp[row][col]=min({op1,op2,op3});
    }
    
    int minFallingPathSum(vector<vector<int>>& arr) 
    {
        int ans=INT_MAX;
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
        for(int j=0; j<arr.size(); j++)
            ans=min(ans,func(arr,0,j,dp));
        return ans;
        
    }
};