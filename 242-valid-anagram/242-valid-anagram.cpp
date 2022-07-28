class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int n=s.size(),m=t.size();
        map<char,int>mp1,mp2;
        if(n!=m)
            return false;
        for(int i=0; i<n; i++)
        {
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        if(mp1==mp2)
            return true;
        return false;
    }
};