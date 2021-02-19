class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int dp[5001][501];
    int func(int amt, vector<int>&coins, int idx)
    {
        if(idx>=coins.size()||amt<0)
            return 0;
        if(dp[amt][idx]!=-1)
            return dp[amt][idx];
        if(amt==0)
            return 1;
        int op1=func(amt-coins[idx],coins,idx);
        int op2=func(amt,coins,idx+1);
        return dp[amt][idx]=op1+op2;
    }
    int change(int amt, vector<int>& coins) 
    {
        if(coins.size()==0&&amt==0)
            return 1;
        memset(dp,-1,sizeof(dp));
        return func(amt,coins,0);
    }
};