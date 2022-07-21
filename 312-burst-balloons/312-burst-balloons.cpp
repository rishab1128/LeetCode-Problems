class Solution {
public:
    
    int recur(vector<int>&arr, int i, int j, vector<vector<int>>&dp)
    {
        if(i+1==j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans = INT_MIN;
        for(int k=i+1; k<j; k++)
        {
            int calc = arr[i]*arr[k]*arr[j];
            ans = max(ans , calc + recur(arr,i,k,dp) + recur(arr,k,j,dp));
        }
        return dp[i][j] = ans;
    }
    
    int bottomUpDP(vector<int>&arr)
    {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
            {
                for(int k=i+1; k<j; k++)
                {
                    int calc = arr[i]*arr[k]*arr[j];
                    dp[i][j] = max(dp[i][j] , calc+dp[i][k]+dp[k][j]);
                }
            }
        }
        return dp[0][n-1];
    }
    
    int maxCoins(vector<int>& arr) 
    {
        arr.insert(arr.begin(),1);
        arr.push_back(1);
        
        
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans1 = recur(arr,0,n-1,dp);
        
        int ans2 = bottomUpDP(arr);
        return ans2;
        
    }
};