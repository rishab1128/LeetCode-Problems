class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int func(vector<vector<int>>& tri , int row, int idx, vector<vector<int>>&dp)
    {
        if(row>=tri.size()||idx>=tri[row].size())
            return 0;
        if(dp[row][idx]!=INT_MAX)
            return dp[row][idx];
        int op1=tri[row][idx]+func(tri,row+1,idx,dp);
        int op2=tri[row][idx]+func(tri,row+1,idx+1,dp);
        return dp[row][idx]=min(op1,op2);
    }
    
    int minimumTotal(vector<vector<int>>& tri) 
    {
        vector<vector<int>>dp(tri.size());
        for(int i=0; i<tri.size(); i++)
        {
            for(int j=0; j<tri[i].size(); j++)
                dp[i].push_back(INT_MAX);
        }
        
        return func(tri,0,0,dp);
    }
};