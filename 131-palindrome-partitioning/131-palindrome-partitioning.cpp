class Solution {
public:
    
    vector<vector<string>>ans;
    
    bool isPalindrome(string&s)
    {
        string t = s;
        reverse(t.begin(),t.end());
        return t==s;
    }
    
    void recur(string& s, int idx, vector<string>&vec)
    {
        if(idx==s.size())
        {
            ans.push_back(vec);
            return;
        }
        string t="";
        for(int i=idx; i<s.size(); i++)
        {
            t+=s[i];
            if(isPalindrome(t))
            {
                vec.push_back(t);
                recur(s,i+1,vec);
                vec.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) 
    {
        vector<string>vec;
        recur(s,0,vec);
        return ans;
    }
};