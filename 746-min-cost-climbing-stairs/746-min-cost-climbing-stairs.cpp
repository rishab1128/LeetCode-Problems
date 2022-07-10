#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Top-Down Approach
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int n;
    int func(vector<int>& cost,vector<int>&dp,int idx)
    {
        if(idx==0||idx==1)
            return cost[idx];
        if(idx<0)
            return 0;
        if(dp[idx])
            return dp[idx];
        return dp[idx]=min(func(cost,dp,idx-1),func(cost,dp,idx-2))+cost[idx];
    }
    
    int minCostClimbingStairs(vector<int>& cost) 
    {
        n=cost.size();
        cost.push_back(0);
        vector<int>dp(n+1,0);
        dp[0]=cost[0];
        dp[1]=cost[1];
        return func(cost,dp,n);
    }
};