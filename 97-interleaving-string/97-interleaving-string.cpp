class Solution {
public:
    int dp[101][101][203];
    bool func(string s1 ,string s2 , string s3 , int i , int j , int k)
    {
       if(i==s1.size())
           return s2.substr(j)==s3.substr(k);
        
        if(j==s2.size())
            return s1.substr(i)==s3.substr(k);
        
        if(dp[i][j][k]>=0)
            return dp[i][j][k] ? true : false;
        
        bool ans=false;
        if(s1[i]==s3[k])
            ans|=func(s1,s2,s3,i+1,j,k+1);
        
        if(s2[j]==s3[k])
            ans|=func(s1,s2,s3,i,j+1,k+1);
        
        dp[i][j][k]=ans;
        
        return ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) 
    {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        memset(dp,-1,sizeof(dp));
        bool ans=func(s1,s2,s3,0,0,0);
        return ans;
        
    }
};