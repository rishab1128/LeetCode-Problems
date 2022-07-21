class Solution {
public:
    vector<vector<bool>> palindromicSubstr(string &s)
    {
        int n  = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n));
        for(int i=0; i<n; i++)
            dp[i][i] = 1;
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
            {
                if(s[i]==s[j])
                {
                    if(j-i==1 || dp[i+1][j-1])
                        dp[i][j] = 1;
                }
            }
        }
        
        return dp;
        
    }

    int recur(string& str, int i, vector<int>&dp, vector<vector<bool>>&dp2)
    {
        if(i==str.size())
            return 0;

        if(dp[i]!=-1)
            return dp[i];

        string s = "";
        int ans = INT_MAX;
        for(int j=i; j<=str.size()-1; j++)
        {
            s += str[j];
            if(dp2[i][j])
            {
                int futureState = recur(str,j+1,dp,dp2);
                ans = min(ans , j!=str.size()-1 ? 1+futureState : futureState);
            }
        }
        return dp[i] = ans;
    }

    int minCut(string str) 
    {
        int n = str.size();
        vector<int>dp(n,-1);
        vector<vector<bool>>dp2 = palindromicSubstr(str);
        int ans = recur(str,0,dp,dp2);
        return ans;
    }

};