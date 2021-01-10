class Solution {
public:
    bool isValid(string s) 
    {
        stack<char>st;
        int n=s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i]=='a')
                st.push(s[i]);
            else if(s[i]=='b')
            {
                if(st.size()>0&&st.top()=='a')
                    st.push(s[i]);
                else
                    return false;
            }
            else if(s[i]=='c')
            {
                if(st.size()>=2&&st.top()=='b')
                {
                    st.pop();
                    st.pop();
                }
                else
                    return false;
            }
        }
        if(st.size()>0)
            return false;
        return true;
        
    }
};
