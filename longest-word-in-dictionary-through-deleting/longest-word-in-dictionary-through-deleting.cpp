bool comp(const string& s1, const string& s2)
{
    return s1.size() > s2.size() || (s1.size() == s2.size() && s1 < s2);
}

class Solution {
public:
    bool check(string d, string s)
    {
        int i=0,j=0;
        if(d.size()>s.size())
            return false;
        while(i<s.size()&&j<d.size())
        {
            if(d[j]==s[i])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        if(j==d.size())
            return true;
        return false;
    }
    
    string findLongestWord(string s, vector<string>& d) 
    {
        string ans;
        sort(d.begin(),d.end(),comp);
        // for(auto x: d)
        //     cout<<x<<" ";
        for(int i=0; i<d.size(); i++)
        {
            if(check(d[i],s))
            {
                ans=d[i];
                break;
            }
        }
        return ans;
    }
};