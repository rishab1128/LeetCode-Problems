class Solution {
public:
    
    int countSubstrAtMostK(string word , int k)
    {
        int n=word.size();
        int left=0,right=0,ans=0 , maxFreq=0;
        unordered_map<char,int>mp;
        while(right<n)
        {
            mp[word[right]]++;
            maxFreq=max(maxFreq , mp[word[right]]);
            while(right-left+1-maxFreq>k)
            {
                mp[word[left]]--;
                if(mp[word[left]]==0)
                    mp.erase(word[left]);
                for(auto [x,y] : mp)
                    maxFreq=max(maxFreq,y);
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }

    int characterReplacement(string s, int k) 
    {
        int ans=countSubstrAtMostK(s,k);
        return ans;
    }
};