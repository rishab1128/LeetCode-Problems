class Solution {
public:
    int coinChange(vector<int>& coins, int amt) 
    {
        long long dp[amt+1];
        dp[0]=0;
        for(int i=1; i<=amt; i++)
        {
            dp[i]=INT_MAX;
            for(int j=0; j<(int)coins.size(); j++)
            {
                if(i-coins[j]>=0)
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
        if(dp[amt]==INT_MAX)
            return -1;
        return dp[amt];
    }
};