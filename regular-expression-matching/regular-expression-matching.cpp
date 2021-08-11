class Solution {
public:
    //Refer Tushar Roy's Video
    bool isMatch(string s, string p) {
        int n=s.size() , m=p.size();
        bool dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int j=2; j<=m; j++)
        {
            if(p[j-1]=='*')
                dp[0][j]=dp[0][j-2];
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='.')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i][j-2];
                    if(j-2>=0 and (p[j-2]==s[i-1] || p[j-2]=='.'))
                        dp[i][j]=dp[i][j] | dp[i-1][j];
                }
                else
                    dp[i][j]=0;
            }
        }
        return dp[n][m];
    }
};