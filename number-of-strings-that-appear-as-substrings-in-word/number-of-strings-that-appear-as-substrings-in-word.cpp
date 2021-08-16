class Solution {
public:
    //KMP algo for pattern matching
    bool check(string pattern , string text)
    {
        string t=pattern+"#"+text;
        vector<int>pi(t.size());
        pi[0]=0;
        for(int i=1; i<t.size(); i++)
        {
            int j=pi[i-1];
            while(j>0 and t[i]!=t[j])
                j=pi[j-1];
            if(t[i]==t[j])
                pi[i]=j+1;
            else
                pi[i]=j;
        }
        for(int i=0; i<t.size(); i++)
        {
            if(pi[i]==pattern.size())
                return true;
        }
        return false;
    }
    
    int numOfStrings(vector<string>& patt, string word) 
    {
        int n=patt.size();
        int ct=0;
        for(int i=0; i<n; i++)
        {
            if(check(patt[i],word))
                ct++;
        }
        return ct;
    }
};