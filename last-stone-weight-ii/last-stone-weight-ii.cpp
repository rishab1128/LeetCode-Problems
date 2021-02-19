class Solution {
public:
    int sum;
    int dp[31][3001];
    
    // wtA : current sum of first subset
    int func(vector<int>& stones, int idx, int wtA)
    {
        if(dp[idx][wtA]!=-1)
            return dp[idx][wtA];
        int ans=0;
        if(idx==stones.size())
        {
            ans=abs(2*wtA-sum); // difference of sums of 2 sets = Math.abs(first_sum - second_sum) = Math.abs(first_sum - (totalSum - first_sum)) = Math.abs(2 * first_sum - totalSum)
        }
        else
            ans=min(func(stones,idx+1,wtA+stones[idx]),func(stones,idx+1,wtA));
        return dp[idx][wtA]=ans;
    }
    
    int lastStoneWeightII(vector<int>& stones) 
    {
        memset(dp,-1,sizeof(dp));
        sum=0;
        for(auto x: stones)
            sum+=x;
        return func(stones,0,0);
    }
};