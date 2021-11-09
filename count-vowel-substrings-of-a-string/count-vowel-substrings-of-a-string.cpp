class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            return true;
        return false;
    }

    //Counts the no. of substrings with at most K vowels (substring contains only vowels)
    int countVowelsAtMostK(string word , int k)
    {
        int left=0, right=0 , n=word.size() , ans=0;
        unordered_map<char,int>mp;
        while(right<n)
        {
            if(!isVowel(word[right]))
            {
                right++;
                left=right;
                mp.clear();
            }
            else
            {
                mp[word[right]]++;
                while(mp.size()>k)
                {
                    mp[word[left]]--;
                    if(mp[word[left]]==0)
                        mp.erase(word[left]);
                    left++;
                }
                ans+=right-left+1;
                right++;
            }
        }

        return ans;
    }

    int countVowelSubstrings(string word)
    {
        int n=word.size();
        //cout<<countVowelsAtMostK(word,5)<<" "<<countVowelsAtMostK(word,4)<<endl;
        int ans=countVowelsAtMostK(word,5)-countVowelsAtMostK(word,4);
        return ans;
    }
};