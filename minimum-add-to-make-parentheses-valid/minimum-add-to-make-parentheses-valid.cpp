class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        stack<char>st;
        int ct=0;
        for(auto x: s)
        {
            if(x=='(')
                st.push(x);
            else
            {
                if(st.size()>0)
                    st.pop();
                else
                    ct++;
            }
        }
        return st.size()+ct;
        
    }
};