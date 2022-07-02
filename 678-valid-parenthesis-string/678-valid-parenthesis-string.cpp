class Solution {
public:
    
    int n;
    int dp[101][101][101];
    
    int recur(string &s, int idx, int op, int cl)
    {
        if(op==cl and idx==n)
            return 1;
        if((cl>op) || idx>=n)
            return 0;
        
        if(dp[idx][op][cl]!=-1)
            return dp[idx][op][cl];
        
        if(s[idx]=='(')
            return dp[idx][op][cl] = recur(s,idx+1,op+1,cl);
        if(s[idx]==')')
            return dp[idx][op][cl] = recur(s,idx+1,op,cl+1);
        
        return dp[idx][op][cl] = recur(s,idx+1,op+1,cl) || recur(s,idx+1,op,cl+1) || recur(s,idx+1,op,cl);
    }
    
    bool checkValidString(string s) 
    {
        memset(dp,-1,sizeof(dp));
        n = s.size();
        int ans = recur(s,0,0,0);
        return ans;
    }
};