class Solution {
public:
    int ans;
    bool isPalin(string &s1)
    {
        string t=s1;
        reverse(t.begin(),t.end());
        return t==s1;
    }
    
    void recur(string &s , int  i, string &s1 , string &s2)
    {
        if(i>=s.size()){
           if(isPalin(s1) and isPalin(s2))
                ans=max(ans,(int)s1.size()*(int)s2.size());
            return;
        }
        
        
        s1.push_back(s[i]);
        recur(s,i+1,s1,s2);
        s1.pop_back();
        
        s2.push_back(s[i]);
        recur(s,i+1,s1,s2);
        s2.pop_back();
        
        recur(s,i+1,s1,s2);
    }
    
    int maxProduct(string s) 
    {
        ans=0;
        string s1="",s2="";
        recur(s,0,s1,s2);
        return ans;
    }
};