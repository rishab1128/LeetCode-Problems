class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.size();
        unordered_map<char,int>mp;
        int left = 0 , right = 0 , ans = 0 ;
        while(right<n)
        {
            if(!mp.count(s[right]))
                mp[s[right]]++;
            else
            {
                ans = max(ans,(int)mp.size());
                while(left<=right and mp.count(s[right]))
                    mp.erase(s[left++]);
                mp[s[right]]++;
            }
            right++;
        }
        
        ans = max(ans,(int)mp.size());
        
        return ans;
        
    }
};