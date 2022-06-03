class Solution {
public:
    vector<vector<bool>> palindromicSubstr(string s)
    {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,0));
        for(int i=0; i<n; i++)
            dp[i][i]=1;
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
            {
                if(s[i]==s[j])
                {
                    if(j-i==1 || dp[i+1][j-1])
                        dp[i][j]=1;
                }
            }
        }
        
        return dp;
    }
    
    int minCut(string s) 
    {
        int n=s.size();
        const int INF=1e7;
        
        vector<int>dp(n,INF);
        vector<vector<bool>>dp2 = palindromicSubstr(s);
        
        dp[0]=0;
        for(int i=1; i<n; i++)
        {
            string str="";
            for(int j=i; j>=0; j--)
            {
                str+=s[j];
                if(dp2[j][i])
                    dp[i]= j-1>=0 ? min(dp[i],dp[j-1]+1) : 0;
            }
        }
        return dp[n-1];
        
    }
};