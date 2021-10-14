class Solution {
public:
    int countVowelStrings(int n) 
    {
        if(n==1)
            return 5;
        
        
        int dp[n+1][5]; 
        
        // 5 => j => 0=a,1=e,2=i,3=o,4=u 
        //dp[i][j] --> number of sorted vowel strings ending with jth character
        //Ans=dp[n][0]+dp[n][1]+dp[n][2]...+dp[n][4];
        
        //Base Case : dp[n][0]=1 for all n since number of strings ending with a is always 1 for all n
        //Fill the first row for n=1
        
        for(int j=0; j<5; j++)
            dp[1][j]=1;
        
        int ans=1;
        for(int i=2; i<=n; i++)
        {
            dp[i][0]=1;
            for(int j=1; j<5; j++){
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
                if(i==n)
                    ans+=dp[i][j];
            }
                
        }
        
        return ans;
        
    }
};