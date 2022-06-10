class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n=s.size();
        if(n==0)
            return 0;
        map<char,int>freq;
        freq[s[0]]++;
        int start=0 , end=1 ;
        int ans=1;
        while(end<n)
        {
            if(freq[s[end]]==0)
                freq[s[end]]++;
            else
            {
                while(freq[s[end]]>=1 and start<end)
                {
                    freq[s[start]]--;
                    start++;
                }
                freq[s[end]]++;
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};