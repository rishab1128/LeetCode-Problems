class Solution {
public:
    string removeDuplicates(string s) 
    {
        string ans="";
        ans+=s[0];
        for(int i=1; i<s.size(); i++)
        {
            if(ans.size()==0)
                ans+=s[i];
            else
            {
                if(ans.back()!=s[i])
                    ans+=s[i];
                else
                    ans.pop_back();
            }
        }
        return ans;
        
    }
};