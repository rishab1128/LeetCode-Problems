class Solution {
public:
    int func(vector<int>s1, vector<int>s2)
    {
        //Same logic as Edit distance
        int m=s1.size() , n=s2.size();
        int dp[m+1][n+1];      //dp[i][j]:=Edit distance b/w strings of len i & j
        int pref1[m+1],pref2[n+1];
        
        pref1[0]=0;
        for(int i=1; i<=m; i++)
            pref1[i]=pref1[i-1]+s1[i-1];
        
        pref2[0]=0;
        for(int i=1; i<=n; i++)
            pref2[i]=pref2[i-1]+s2[i-1];
        
        for(int i=0; i<=m; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==0)
                    dp[0][j]=pref2[j]; //Deleting j chars from s2 (Base Case 1 , m=0)
                else if(j==0)
                    dp[i][0]=pref1[i]; //Deleting i chars from s1 (Base Case 2 , n=0)
                else if(i!=0 and j!=0)
                {
                    if(s1[i-1]==s2[j-1])
                        dp[i][j]=dp[i-1][j-1];
                    else
                        dp[i][j]=min(s1[i-1]+dp[i-1][j],s2[j-1]+dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
        
    }
    
    int minimumDeleteSum(string s1, string s2) 
    {
        vector<int>v1,v2;
        for(int i=0; i<s1.size(); i++)
        {
            int x=(int)s1[i];
            v1.push_back(x);
        }
        for(int i=0; i<s2.size(); i++)
        {
            int x=(int)s2[i];
            v2.push_back(x);
        }
        
        return func(v1,v2);
        
    }
};