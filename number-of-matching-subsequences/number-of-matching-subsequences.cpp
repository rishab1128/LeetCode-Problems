class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        //Using map and binary-search
        map<char,vector<int>>mp;
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]].push_back(i);
        }
        int ans=0;
        for(auto word:words)
        {
            int x=-1;
            bool tmp=true;
            for(auto ch:word)
            {
                if(mp.count(ch))
                {
                    auto pos=upper_bound(mp[ch].begin() , mp[ch].end() , x);
                    if(pos==mp[ch].end())
                    {
                        tmp=false;
                        break;
                    }
                    x=*pos;
                }
                else
                    tmp=false;
            }
            if(tmp)
                ans++;
        }
        return ans;
        
    }
};