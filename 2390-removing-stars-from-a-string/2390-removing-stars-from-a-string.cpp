class Solution {
public:
    string removeStars(string s) 
    {
        int n = s.size();
        stack<char>st;
        for(auto ch : s)
        {
            if(ch!='*')
                st.push(ch);
            else
                st.pop();
        }
        string ans = "";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};