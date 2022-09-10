class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int dp[1005][105][2];
    
    int func(vector<int>& prices, int k, int idx, int flag)
    {
        if(idx>=(int)prices.size()||k==0)
            return 0;
        if(dp[idx][k][flag])
            return dp[idx][k][flag];
        int buy=0,no_buy=0,sell=0,no_sell=0;
        if(flag==0) //no active transaction is going on
        {
            buy=func(prices,k,idx+1,1)-prices[idx];
            no_buy=func(prices,k,idx+1,0);
        }
        else //an active transaction is on
        {
            sell=func(prices,k-1,idx+1,0)+prices[idx];
            no_sell=func(prices,k,idx+1,1);
        }
        
        return dp[idx][k][flag]=max({buy,no_buy,sell,no_sell});
        
    }
    
    int maxProfit(int k, vector<int>& prices) 
    {
        memset(dp,0,sizeof(dp));
        int n=prices.size();
        if(2*k>n)
        {
            int profit=0;
            for(int i=1; i<n; i++)
            {
                if(prices[i]>prices[i-1])
                    profit+=prices[i]-prices[i-1];
            }
            return profit;
        }
        return func(prices,k,0,0);
    }
};