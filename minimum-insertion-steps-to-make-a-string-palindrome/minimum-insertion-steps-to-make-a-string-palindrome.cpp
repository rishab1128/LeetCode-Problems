class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    
    int func(string&s, int left, int right, vector<vector<int>>&dp)
    {
        if(left==right)
            return 1;
        if(left>right)
            return 0;
        if(dp[left][right])
            return dp[left][right];
        if(s[left]==s[right])
            return dp[left][right]=2+func(s,left+1,right-1,dp);
        else
            return dp[left][right]=max(func(s,left+1,right,dp),func(s,left,right-1,dp));
        return dp[left][right];
    }
    
    int minInsertions(string s) 
    {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n));
        int x=func(s,0,n-1,dp);
        cout<<x<<endl;
        return n-x;
    }
};