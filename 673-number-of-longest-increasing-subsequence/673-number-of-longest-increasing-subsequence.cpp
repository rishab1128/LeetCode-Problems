class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) 
    {
        int n = arr.size();
        int dp[n] , cnt[n];
        dp[0] = 1 , cnt[0] = 1;
        int idx = -1 , maxi = dp[0];
        for(int i=1; i<n; i++)
        {
            dp[i] = 1;
            cnt[i] = 1;
            for(int j=i-1; j>=0; j--)
            {
                if(arr[j]<arr[i])
                {
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[i]==dp[j]+1)
                        cnt[i] += cnt[j];
                   
                }   
            }
            maxi = max(maxi,dp[i]);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(dp[i]==maxi)
                ans += cnt[i];
        }
        
        return ans;
        
        
        
    }
};