class Solution {
public:
    bool check(string word1, string word2, int i, int j)
    {
        int n=word1.size(),m=word2.size();
        while(i<n&&j<m)
        {
            if(word1[i]==word2[j])
            {
                i++,j++;
                continue;
            }
            else if(word1[i]>word2[j])
                return true;
            else
                return false;
        }
        if(i<n)
            return true;
        return false;
    }
    string largestMerge(string word1, string word2) 
    {
        int n=word1.size(),m=word2.size();
        string ans="";
        int i=0,j=0;
        while(i<n&&j<m)
        {
            if(word1[i]>word2[j])
            {
                ans+=word1[i];
                i++;
            }
            else if(word1[i]<word2[j])
            {
                ans+=word2[j];
                j++;
            }
            else
            {
                if(check(word1,word2,i,j))
                    ans+=word1[i++];
                else
                    ans+=word2[j++];
            }
        }
        while(i<n)
            ans+=word1[i],i++;
        while(j<m)
            ans+=word2[j],j++;
        return ans;
    }
};