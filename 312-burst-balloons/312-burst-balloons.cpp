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
    
    int maxCoins(vector<int>& arr) 
    {
        arr.insert(arr.begin(),1);
        arr.push_back(1);
        
        
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans = recur(arr,0,n-1,dp);
        return ans;
        
    }
};