class Solution {
public:
    int longestValidParentheses(string s) 
    {
        stack<int>st;
        int n=s.size();
        int len=0;
        st.push(-1);
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                if(st.size()>0)
                {
                    st.pop();
                    if(st.size()>0)
                    {
                        int idx=st.top();
                        len=max(len,i-idx);
                    }
                    if(st.size()==0)
                        st.push(i);
                }
            }
        }
        return len;
        
    }
};