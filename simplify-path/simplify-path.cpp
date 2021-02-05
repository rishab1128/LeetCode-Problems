class Solution {
public:
    string simplifyPath(string path) 
    {
        string ans,str;
        stringstream ss(path);
        stack<string>st;
        while(getline(ss,str,'/'))
        {
            if(str==""||str==".")
                continue;
            if(str==".."&&st.size()>0)
                st.pop();
            else if(str!="..")
                st.push(str);
        }
        while(st.size()>0)
        {
            ans="/"+st.top()+ans;
            st.pop();
        }
        return ans.empty()?"/":ans;
    }
};