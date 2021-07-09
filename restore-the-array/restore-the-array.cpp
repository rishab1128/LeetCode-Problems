class Solution {
public:
    int dp[100001]; // dp[i] is number of ways to print valid arrays from string s start at i
    const int MOD=1e9+7;
    int recur(const string &s, int i, int&k)
    {
        if(i==s.size()) // base case -> Found a valid way
            return 1;
        if(s[i]=='0')   // all numbers are in range [1, k] and there are no leading zeros -> So numbers starting with 0 mean invalid!
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        
        int ans=0;
        long long num=0;
        for(int j=i; j<s.size(); j++)
        {
            num=num*10+(s[j]-'0');  // num is the value of the substring s[i..j]
            if(num>k)
                break;
            ans+=recur(s,j+1,k);
            ans%=MOD;
        }
        return dp[i]=ans;
    }

    int numberOfArrays(string s, int k) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=recur(s,0,k);
        return ans;
    }
};