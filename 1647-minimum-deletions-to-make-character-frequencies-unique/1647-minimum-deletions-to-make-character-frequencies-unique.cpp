#define rsort(a)   sort(a.rbegin(), a.rend())
class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int minDeletions(string s) 
    {
        int freq[26]={},ans=0;
        unordered_map<int,int>already_hai;
        for(auto x: s)
            freq[x-'a']++;
        for(int i=0; i<26; i++)
        {
            int ct=freq[i];
            while(ct>0&&already_hai.find(ct)!=already_hai.end())
            {
                ct--;
                ans++;
            }
            if(ct>0&&already_hai.find(ct)==already_hai.end())
                already_hai.insert({ct,1});
        }
        return ans;
    }
};