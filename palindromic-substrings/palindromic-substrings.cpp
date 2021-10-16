class Solution {
public:
    int countSubstrings(string s) 
    {
        int n=s.size();
        if(n<2)
            return n;
        vector<vector<bool>>dp(n,vector<bool>(n,false));//dp[i][j] -> Tells whether s[i..j] is a palindrome or not
        int ct=0;
        for(int i=0; i<n; i++){
            dp[i][i]=1;
            ct++;
        }
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
            {
                if(s[i]==s[j])
                {
                    if(j-i==1 || dp[i+1][j-1])
                    {
                        ct++;
                        dp[i][j]=1;
                    }
                }
            }
        }
        
        return ct;
            
        
        
        
    }
};