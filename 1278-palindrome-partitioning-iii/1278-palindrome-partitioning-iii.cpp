class Solution {
public:
    
    map<pair<string,int>,int>dp;
    
    int func(string s)
    {
        int i=0,j=s.size()-1,cnt=0;
        while(i<j)
        {
            if(s[i]!=s[j])
                cnt++;
            i++;
            j--;
        }
        return cnt;
    }
    
    int recur(string s, int k)
    {
        if(s.size()==1 || k==s.size())
            return 0;
        if(k==1)
            return func(s);
        
        if(dp.count({s,k}))
            return dp[{s,k}];
        
        int ans = INT_MAX;
        for(int len=1; len<=s.size()-k+1; len++)
        {
            string str1 = s.substr(0,len);
            string str2 = s.substr(len);
            int req = func(str1);
            ans = min(ans,req+recur(str2,k-1));
        }
        return dp[{s,k}]=ans;
    }
    
    int palindromePartition(string s, int k) 
    {
        dp.clear();
        int ans = recur(s,k);
        return ans;    
    }
};