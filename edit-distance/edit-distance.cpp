class Solution {
public:
    //Recursive DP
    int dp[501][501];
    int recur(string s1 , string s2 , int i, int j)
    {
        //Base Cases
        if(i==s1.size())
            return s2.size()-j; //Insert remaining chars from s2
        
        if(j==s2.size())
            return s1.size()-i; //Delete reamining chars from s1
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans;
        if(s1[i]==s2[j])
            ans=recur(s1,s2,i+1,j+1);
        else        
        {
            //insert
            int insert=recur(s1,s2,i,j+1);
            //delete
            int del=recur(s1,s2,i+1,j);
            //replace
            int replace=recur(s1,s2,i+1,j+1);
            
            ans=min({insert , del , replace})+1;
        }
        return dp[i][j]=ans;
    }
    
    int minDistance(string s1, string s2) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=recur(s1,s2,0,0);
        return ans;
    }
};