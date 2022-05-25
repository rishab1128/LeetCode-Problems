class Solution {
public:
    int dp[601][101][101];
    int recur(vector<string>& strs, int i, int m, int n)
    {
        if(i==(int)strs.size())
            return 0;
        
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        
        int ct0=0,ct1=0;
        for(auto x : strs[i]){
            if(x=='0')
                ct0++;
            else
                ct1++;
        }
        if(m>=ct0 and n>=ct1){
            int op1 = 1+recur(strs,i+1,m-ct0,n-ct1);
            int op2 = recur(strs , i+1 , m, n);
            return dp[i][m][n]=max(op1,op2);
        }
        int op = recur(strs ,  i+1 , m, n);
        return dp[i][m][n]=op;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        memset(dp,-1,sizeof(dp));
        int ans = recur(strs,0,m,n);
        return ans;
        
    }
};