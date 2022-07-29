#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool comp(string& word, string &pattern)
    {
        int n = pattern.size();
        unordered_map<char,char>mp1,mp2;
        for(int i=0; i<n; i++)
        {
            if(!mp1.count(pattern[i]))
            {
                if(mp2.count(word[i]) and mp2[word[i]]!=pattern[i])
                {
                    return false;
                }
                else if(mp2.count(word[i]) and mp2[word[i]]==pattern[i])
                    mp1[pattern[i]] = word[i];
                else if(!mp2.count(word[i]))
                {
                    mp1[pattern[i]] = word[i];
                    mp2[word[i]] = pattern[i];
                }
            }
            else
            {
                if(mp1[pattern[i]]!=word[i])
                    return false;
            }
        }
        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string>ans;
        int n=words.size();
        int m=pattern.size();
        for(int i=0; i<n; i++)
        {
            if(comp(words[i],pattern))
                ans.push_back(words[i]);
        }
        return ans;
        
    }
};


