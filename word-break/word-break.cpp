#include<bits/stdc++.h>
using namespace std;
​
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string>st;
        for(auto x: wordDict)
            st.insert(x);
        int n=s.size();
        vector<bool>dp(n,0);
        string t="";
        t+=s[n-1];
        if(st.find(t)!=st.end())
            dp[n-1]=1;
        else
            dp[n-1]=0;
        for(int i=n-2; i>=0; i--)
        {
            dp[i]=0;
            string t="";
            for(int j=i; j<n; j++)
            {
                t+=s[j];
                if(st.find(t)!=st.end())
                {
                    if(j+1<n&&dp[j+1])
                    {
                        dp[i]=1;
                        break;
                    }
                    else if(j+1==n)
                    {
                        dp[i]=1;
                        break;
                    }
                }
            }
        }
        return dp[0];
        
    }
};
