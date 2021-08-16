class Solution {
public:
    string decodeString(string s) 
    {
        int n=s.size();
        stack<string>st;
        for(int i=0; i<n; i++)
        {
            if(s[i]!=']')
            {
                string t="";
                t+=s[i];
                st.push(t);
            }
            else
            {
                vector<string>v;
                while(st.size()>0 and st.top()!="[")
                {
                    v.push_back(st.top());
                    st.pop();
                }
                st.pop();
                
                //For handling multi-digit numbers
                string num="";
                while(st.size()>0 and st.top()>="0" and st.top()<="9")
                {
                    num+=st.top();
                    st.pop();
                }
                reverse(num.begin(),num.end());
                int number=stoi(num);
                
                
                reverse(v.begin(),v.end());
                string t="";
                for(auto x: v)
                    t+=x;
                
                string z="";
                for(int i=0; i<number; i++)
                    z+=t;
                
                st.push(z);
            }
        }
        
        vector<string>v;
        while(st.size()>0){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        string ans="";
        for(auto x: v)
            ans+=x;
            
        return ans;
        
    }
};