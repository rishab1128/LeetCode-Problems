class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        int n=num.size();
        if(k==n)
            return "0";
        stack<char>st;
        for(int i=0; i<n; i++)
        {
            while(k>0 and !st.empty() and st.top()>num[i])
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        //Corner Case  : For strings like "11111"
        while(st.size()>0 and k>0)
        {
            st.pop();
            k--;
        }
        
        string ans="";
        while(st.size()>0)
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        //Remove starting 0's
        int len=ans.size() , pos=0;
        for(int i=0; i<ans.size()-1; i++)
        {
            if(ans[i]=='0')
            {
                pos++;
                len--;
            }
            else
                break;
        }
        
        return ans.substr(pos,len);
    }
};