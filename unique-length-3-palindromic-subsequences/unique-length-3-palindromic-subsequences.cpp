class Solution {
public:
    //We just need to calculate the number of unique chractrers b/w the first occu and the last occu of a particular character
    int countPalindromicSubsequence(string s)
    {
        int n=s.size() ;
        
        //Store the position of occurence of all unique characters in map mp 
        map<char,vector<int>>mp;
        for(int i=0; i<n; i++)
        {
            mp[s[i]].push_back(i);
        }
        
        int ans=0;
        //TC : O(n*26);
        for(auto x: mp)
        {
            char ch=x.first;
            int sz=mp[ch].size() ;
            int first=mp[ch][0] , last=mp[ch][sz-1];
            for(char j='a' ; j<='z'; j++)
            {
                if(mp.find(j)!=mp.end())
                {
                    // cout<<ch<<"-->"<<j<<" "<<first<<" "<<last<<endl;
                    auto pos=upper_bound(mp[j].begin() , mp[j].end() , first) ;
                    if(pos!=mp[j].end() and *pos>first and *pos<last)
                    {
                        ans++;
                    }
                        
                }
            }
        }
        return ans;
        
    }
};