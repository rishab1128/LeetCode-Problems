class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    //Iterative-DP-Bottom-Up Approach-Using O(N) space
    int minimumTotal(vector<vector<int>>& tri) 
    {
        int n=tri.size();
        vector<int>dp(n),tmp(n,0);
        //Remember base case is just returning leaf nodes
        for(int j=0; j<tri[n-1].size(); j++)
            dp[j]=tri[n-1][j];
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=0; j<tri[i].size(); j++)
                tmp[j]=tri[i][j]+min(dp[j],dp[j+1]);
            dp=tmp;
        }
        
        return dp[0];
        
        
    }
};