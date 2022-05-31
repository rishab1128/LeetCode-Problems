class Solution {
public:
    string strWithout3a3b(int a, int b) 
    {
        string ans="";
        while(a>0 and b>0)
        {
            if(a>b)
            {
                ans+="aab";
                a--;
            }
            else if(b>a)
            {
                ans+="bba";
                b--;
            }
            else
                ans+="ab";
            a--;
            b--;
        }
        while(a>0)
            ans+='a',a--;
        while(b>0)
            ans+='b',b--;
        
        return ans;
        
    }
};