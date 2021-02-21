class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    string minRemoveToMakeValid(string s) 
    {
        stack<int>st;
        for (auto i = 0; i < s.size(); ++i)
        {
            if(s[i]=='(')
                st.push(i);
            else if(s[i]==')')
            {
                if(st.size()>0)
                    st.pop();
                else
                    s[i]='?';
            }
        }
        while(st.size()>0)
        {
            s[st.top()]='?';
            st.pop();
        }
        s.erase(remove(s.begin(), s.end(), '?'), s.end());
        return s;
    }
};