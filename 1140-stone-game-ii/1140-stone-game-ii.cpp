class Solution {
public:
    int n;
    int dp[101][101];
    
    int recur(vector<int>&arr, int idx, int m)
    {
        if(idx>=n)
            return 0;
        
        if(dp[idx][m]!=-1)
            return dp[idx][m];
        
        if(idx+2*m>=n)
        {
            int sum = 0;
            for(int i=idx; i<n; i++)
                sum+=arr[i];
            return dp[idx][m] = sum;
        }
        
        int sum = 0;
        int bob = INT_MAX;
        
        for(int x=1; x<=2*m; x++)
            bob = min(bob , recur(arr,idx+x,max(m,x)));
        
        for(int j=idx; j<n; j++)
            sum+=arr[j];
        
        return dp[idx][m] = sum - bob; //alice + bob = sum;
    }
    
    int stoneGameII(vector<int>& arr) 
    {
        memset(dp,-1,sizeof(dp));
        n = arr.size();
        int ans = recur(arr,0,1);
        return ans;
    }
};