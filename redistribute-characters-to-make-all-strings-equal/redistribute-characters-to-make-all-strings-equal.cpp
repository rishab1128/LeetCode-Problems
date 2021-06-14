class Solution {
public:
    bool makeEqual(vector<string>& words) 
    {
        map<char,int>mp;
        int n=words.size();
        for(auto word:words)
        {
            for(auto ch:word)
                mp[ch]++;
        }
        for(auto x: mp)
        {
            if(x.second%n)
                return false;
        }
        return true;
        
    }
};