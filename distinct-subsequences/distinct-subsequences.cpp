class Solution {
public:
    int dp[1001][1001];
    int recur(string&s , string&t , int i , int j)
    {
        if(i>=s.size() and j<t.size())
            return 0;
        if(j==t.size())
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];

        if(s[i]==t[j])
            return dp[i][j]=recur(s,t,i+1,j+1)+recur(s,t,i+1,j);
        return dp[i][j]=recur(s,t,i+1,j);
    }
    int numDistinct(string s, string t) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=recur(s,t,0,0);
        return ans;
    }

};