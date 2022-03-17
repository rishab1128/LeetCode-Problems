class Solution {
public:
    //Reference : Soln
    //Using stack
    int scoreOfParentheses(string s) 
    {
        int n=s.size();
        stack<int>st;
        st.push(0);
        
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
                st.push(0);
            else
            {
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                st.push(t2+max(2*t1,1));
            }
        }
        return st.top();
    }
};