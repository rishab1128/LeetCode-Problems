class Solution {
public:
    
    unordered_map<int,vector<int>>pos;
    
    int recur(string&s , int idx, int prev, int&k, vector<vector<int>>&dp)
    {
        if(idx==s.size())
            return 0;
        
        if(dp[idx][prev]!=-1)
            return dp[idx][prev];
        
        int op1 = recur(s,idx+1,prev,k,dp);
        
        int op2 = 0;
        int curr = (s[idx]-'a')+1;
        if(prev==0 || abs(curr-prev)<=k)
            op2 = 1+recur(s,idx+1,curr,k,dp);
        
        return dp[idx][prev] = max(op1,op2);
    }
    
    int longestIdealString(string s, int k) 
    {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(27,-1));
        return recur(s,0,0,k,dp);
    }
};