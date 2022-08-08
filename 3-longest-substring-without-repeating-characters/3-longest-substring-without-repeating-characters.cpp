class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.size();
        vector<int>freq(128,0);
        int left = 0 , right = 0 , ans = 0 , len = 0 ;
        while(right<n)
        {
            int ascii = (int)s[right];
            if(!freq[ascii]){
                freq[ascii]++;
                len++;
            }
            else
            {
                ans = max(ans,len);
                while(left<=right and freq[ascii])
                {
                    int ascii2 = (int)s[left];
                    freq[ascii2]--;
                    left++;
                    len--;
                }
                freq[ascii]++;
                len++;
            }
            right++;
        }
        
        ans = max(ans,len);
        
        return ans;
        
    }
};