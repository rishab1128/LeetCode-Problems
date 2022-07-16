class Solution {
public:
    int maxSumDivThree(vector<int>& arr) 
    {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(3,0));
        
        dp[0][arr[0]%3]=arr[0];
        
        for(int i=1; i<n; i++)
        {
            int rem = arr[i]%3;
            if(rem==0){
                dp[i][0] = max(dp[i-1][0], arr[i]+dp[i-1][0]);
                dp[i][1] = dp[i-1][1]>0 ? max(arr[i]+dp[i-1][1],dp[i-1][1]) : dp[i-1][1];
                dp[i][2] = dp[i-1][2]>0 ? max(arr[i]+dp[i-1][2],dp[i-1][2]) : dp[i-1][2];
            }
            else if(rem==1)
            {
                dp[i][0] = dp[i-1][2]>0 ? max(arr[i]+dp[i-1][2],dp[i-1][0]) : dp[i-1][0];
                dp[i][1] = max(arr[i]+dp[i-1][0],dp[i-1][1]);
                dp[i][2] = dp[i-1][1]>0 ? max(arr[i]+dp[i-1][1],dp[i-1][2]) : dp[i-1][2];
            }
            else
            {
                dp[i][0] = dp[i-1][1]>0 ? max(arr[i]+dp[i-1][1],dp[i-1][0]) : dp[i-1][0];
                dp[i][1] = dp[i-1][2]>0 ? max(arr[i]+dp[i-1][2],dp[i-1][1]) : dp[i-1][1];
                dp[i][2] = max(arr[i]+dp[i-1][0],dp[i-1][2]);
            }
        }
        
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<3; j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        
        return dp[n-1][0];
        
        
    }
};