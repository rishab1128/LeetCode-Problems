class Solution {
public:
    string defangIPaddr(string add) 
    {
        int n=add.size();
        string ans="";
        for(int i=0; i<n; i++)
        {
            if(add[i]=='.')
            {
                ans+="[.]";
            }
            else
                ans+=add[i];
        }
        return ans;
            
        
    }
};