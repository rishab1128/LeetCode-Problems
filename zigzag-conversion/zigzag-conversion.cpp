class Solution {
public:
    string convert(string s, int rows) 
    {
        if(rows==1)
            return s;
        vector<string>ans(rows,"");
        int n=s.size() ;
        int flag=1,j=0;
        for(int i=0; i<n; i++)
        {
            if(flag==1)
            {
                ans[j]+=s[i];
                j++; 
                if(j==rows)
                {
                    j=rows-2;
                    flag=0;
                }
            }
            else
            {
                ans[j]+=s[i];
                j--; 
                if(j==-1)
                {
                    j=1;
                    flag=1;
                }
            }    
        }
        string res="";
        for(auto x: ans)
            res+=x;
        return res;
        
    }
};