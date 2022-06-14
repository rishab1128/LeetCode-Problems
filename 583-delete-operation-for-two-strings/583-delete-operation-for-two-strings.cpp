class Solution {
public:
    int dp[501][501];
    int lcs(string&s1, string&s2, int i, int j)
    {
        if(i>=s1.size() ||  j>=s2.size())
            return 0;
        if(dp[i][j])
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j]=1+lcs(s1,s2,i+1,j+1);
        return dp[i][j]=max(lcs(s1,s2,i+1,j), lcs(s1,s2,i,j+1));
    }
    
    int minDistance(string word1, string word2) 
    {
        memset(dp,0,sizeof(dp));
        int n=word1.size() , m=word2.size();
        int lcs_len=lcs(word1,word2,0,0);
        int ans=n-lcs_len+m-lcs_len;
        return ans;
        
    }
};