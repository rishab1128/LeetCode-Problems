class Solution {
public:
    string reverseParentheses(string s) 
    {
       
        string ans="" , tmp;
        int n = s.size();
        stack<char>st;
        for(auto &x: s)
        {
            if(x!=')')
            {
                if(x=='(' || st.size())
                    st.push(x);
                else
                    ans+=x;
            }
            else
            {
                tmp="";
                while(st.size() and st.top()!='(')
                {
                    tmp+=st.top();
                    st.pop();
                }
                st.pop();
                if(st.size())
                {
                    for(auto &y: tmp)
                        st.push(y);
                }
                else
                    ans+=tmp;
            }
        }
        
        
        return ans;
        
        
        
    }
};