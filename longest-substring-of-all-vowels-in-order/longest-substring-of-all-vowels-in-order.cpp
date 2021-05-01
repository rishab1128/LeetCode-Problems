class Solution {
public:
    int longestBeautifulSubstring(string word) 
    {
        int n=word.size() , cnt=1, len=1 , ans=0;
        for(int i=1; i<n; i++)
        {
            if(word[i]==word[i-1])
            {
                len++;
            }
            else if(word[i]>word[i-1])
            {
                cnt++;
                len++;
            }
            else
            {
                cnt=1;
                len=1;
            }
            if(cnt==5)
                ans=max(ans,len);
        }
        return ans;
        
    }
};