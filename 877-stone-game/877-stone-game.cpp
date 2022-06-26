class Solution {
public:
    int dp[501][501];
    int recur(vector<int>&arr, int i, int j, int flag)
    {
        if(i>j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int alice = 0;
        if(!flag)
        {
            int op1 = arr[i]+recur(arr,i+1,j,flag^1);
            int op2 = arr[j]+recur(arr,i,j-1,flag^1);
            alice=max(op1,op2);
        }
        else
        {
            int op1 = -arr[i]+recur(arr,i+1,j,flag^1);
            int op2 = -arr[j]+recur(arr,i,j-1,flag^1);
            alice = min(op1,op2);
        }
        return dp[i][j]=alice;
        
    }
    
    bool stoneGame(vector<int>& arr) 
    {
        memset(dp,-1,sizeof(dp));
        int n = arr.size();
        int diff = recur(arr,0,n-1,0);
        return diff>0;
    }
};
