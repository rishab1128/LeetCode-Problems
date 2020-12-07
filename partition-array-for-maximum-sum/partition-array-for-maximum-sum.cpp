#include<bits/stdc++.h>
using namespace std;
​
class Solution 
{
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        //dp[i]-->record the max sum considering A[0]~A[i]
        int n=arr.size();
        vector<int>dp(n,0);
        for(int i=0; i<n; i++)
        {
            int maxi=0;
            for(int j=1; j<=k&&i-j+1>=0; j++)
            {
                maxi=max(maxi,arr[i-j+1]);
                dp[i]=max(dp[i],((i-j>=0?dp[i-j]:0)+maxi*j));
            }
        }
        return dp[n-1];
    }
};
