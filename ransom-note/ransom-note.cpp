class Solution {
public:
    bool canConstruct(string a, string b) 
    {
        //make a using b
        map<char,int>mp1,mp2;
        for(auto x: a)
        {
            mp1[x]++;
        }
        for(auto x: b)
        {
            mp2[x]++;
        }
        for(auto ele : mp1)
        {
            char ch=ele.first;
            if(mp2[ch]>=mp1[ch])
                continue;
            else
                return false;
        }
        return true;
    }
};