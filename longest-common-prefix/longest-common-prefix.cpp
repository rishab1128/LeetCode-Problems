bool comp(const string&s1, const string&s2)
{
    return s1.size()<s2.size();
}
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.size()==0)
            return "";
        sort(strs.begin(),strs.end(),comp);
        int len=0,flag=0;
        for(int i=1; i<=strs[0].size(); i++)
        {
            for(int j=1; j<strs.size(); j++)
            {
                if(strs[j].substr(0,i)==strs[0].substr(0,i))
                    continue;
                else
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
                len=max(len,i);
            else
                break;
        }
        return strs[0].substr(0,len);
        
    }
};