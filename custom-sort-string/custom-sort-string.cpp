class Solution {
public:
    string customSortString(string order, string str) 
    {
        
        map<char,int>mp;
        for(auto x: str)
            mp[x]++;
        
        string ans="";
        for(auto x: order)
        {
            for(int i=0; i<mp[x]; i++)
                ans+=x;
            mp.erase(x);
        }
    
        
        for(auto x: mp)
        {
            char ch=x.first;
            for(int i=0; i<mp[ch]; i++)
                ans+=ch;
        }
        return ans;
    
    }
};