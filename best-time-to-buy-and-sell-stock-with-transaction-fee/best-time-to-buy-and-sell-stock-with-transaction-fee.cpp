class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int dp[100005][2];
    
    int func(vector<int>& prices, int idx, int flag, int fee)
    {
        if(idx>=(int)prices.size())
            return 0;
        if(dp[idx][flag])
            return dp[idx][flag];
        int buy=0,no_buy=0,sell=0,no_sell=0;
        if(flag==0) //no active transaction is going on
        {
            buy=func(prices,idx+1,1,fee)-prices[idx];
            no_buy=func(prices,idx+1,0,fee);
        }
        else //an active transaction is on
        {
            sell=func(prices,idx+1,0,fee)+prices[idx]-fee;
            no_sell=func(prices,idx+1,1,fee);
        }
        
        return dp[idx][flag]=max({buy,no_buy,sell,no_sell});
        
    }
    
    int maxProfit(vector<int>& prices, int fee) 
    {
        memset(dp,0,sizeof(dp));
        int n=prices.size();
        return func(prices,0,0,fee);
    }
};