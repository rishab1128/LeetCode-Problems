unordered_map<string,int>mp;
vector<string>v;

void recur(string s, string ans)
{
    if(s.size()==0)
    {
        v.push_back(ans);
        return;
    }
    for(int len=1; len<=s.size(); len++)
    {
        string t=s.substr(0,len);
        string z=len<s.size() ? s.substr(len) : "";
        if(mp[t])
        {
            ans+=t;
            ans+=" ";
            recur(z,ans);
            for(int i=0; i<=t.size(); i++)
                ans.pop_back();
        }
    }
}

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        mp.clear();
        v.clear();
        
        for(auto x: wordDict)
            mp[x]=1;
        
        recur(s,"");
        for(auto &x: v)
            x.pop_back();
        return v;
        
    }
};