unordered_map<string,int>mp;
unordered_map<string,vector<string>>dp;


vector<string> recur(string s)
{
    vector<string> res;
    
    if(s.size()==0)
    {
        res.push_back(" ");
        return res;
    }
    
    if(dp.count(s))
        return dp[s];
    
    for(int len=1; len<=s.size(); len++)
    {
        string t=s.substr(0,len);
        string z=len<s.size() ? s.substr(len) : "";
        if(mp[t])
        {
            vector<string> rem = recur(z);
            for(auto x: rem)
            {
                if(x==" ")
                    res.push_back(t);
                else
                    res.push_back(t+" "+x);
            }
        }
    }
    
    return dp[s]=res;
}

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        mp.clear();
        dp.clear();
        
        for(auto x: wordDict)
            mp[x]=1;
        
        return recur(s);
    }
};