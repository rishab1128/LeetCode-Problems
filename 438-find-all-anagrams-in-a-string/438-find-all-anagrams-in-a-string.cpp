class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        int n=s.size() , m=p.size();
        map<char,int>mp1,mp2;
        vector<int>ans;
        for(auto x: p)
            mp2[x]++;
        for(int i=0; i<m; i++)
        {
            mp1[s[i]]++;
        }
        if(mp1==mp2)
            ans.push_back(0);
        int j=0;
        for(int i=m; i<n; i++)
        {
            if(mp1[s[j]]>0)
            {
                mp1[s[j]]--;
                if(mp1[s[j]]==0)
                    mp1.erase(s[j]);
                j++;
            }
            mp1[s[i]]++;
            if(mp1==mp2)
                ans.push_back(j);
        }
        
        return ans;
    }
};