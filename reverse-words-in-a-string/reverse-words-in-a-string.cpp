class Solution {
public:
    string reverseWords(string str) 
    {
        stringstream s(str); 
        string word; 
        stack<string>st;
        while (s >> word)
            st.push(word);
        
        string ans="";
        while(st.size()!=1)
        {
            ans+=st.top();
            ans+=" ";
            st.pop();
        }
        ans+=st.top();
        st.pop();
        return ans;
    }
};