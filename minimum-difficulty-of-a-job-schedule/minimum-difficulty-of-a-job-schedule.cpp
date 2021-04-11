class Solution {
public:
    int n;
    int dp[11][301];
    int func(vector<int>&arr, int d, int idx)
    {
        if(d==0 && idx<n)
        {
            int maxi=arr[idx];
            for(int i=idx; i<n; i++)
                maxi=max(maxi,arr[i]);
            return maxi;
        }
        
        if(dp[d][idx]!=-1)
            return dp[d][idx];
        
        
        int maxi=0,mini=INT_MAX;
        
        for(int i = idx; i<n-d; i++) 
        {
            maxi = max(maxi, arr[i]);
            mini = min(mini, maxi + func(arr, d-1, i+1));
        }
        
		return dp[d][idx]=mini;
        
        
    }
    int minDifficulty(vector<int>& arr, int d) 
    {
        n=arr.size();
        if(n<d)
            return -1;
        memset(dp,-1,sizeof(dp));
        return func(arr,d-1,0);
    }
};