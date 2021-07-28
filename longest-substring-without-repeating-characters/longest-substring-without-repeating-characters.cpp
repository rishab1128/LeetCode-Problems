class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n=s.size();
        if(n==0)
            return 0;
        map<char,int>mp;
        mp[s[0]]++;
        int start=0 , end=1 ;
        int ans=1;
        while(end<n)
        {
            if(mp[s[end]]==0)
                mp[s[end]]++;
            else
            {
                while(mp[s[end]]>=1 and start<end)
                {
                    mp[s[start]]--;
                    start++;
                }
                mp[s[end]]++;
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};