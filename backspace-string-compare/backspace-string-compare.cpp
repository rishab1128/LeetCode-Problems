class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        stack<char> st , st2;
        for(int i=0; i<s.size(); i++)
        {
            if(st.size()>0 and s[i]=='#'){
                st.pop();
                continue;
            }
            else if(st.size()==0 and s[i]=='#')
                continue;
                
            st.push(s[i]);
        }
        for(int i=0; i<t.size(); i++)
        {
            if(st2.size()>0 and t[i]=='#'){
                st2.pop() ;
                continue;
            }
            else if(st2.size()==0 and t[i]=='#')
                continue;
                
            st2.push(t[i]);
        }
        string x="",y="";
        while(st.size()>0)
        {
            x+=st.top();
            st.pop();
        }
        while(st2.size()>0)
        {
            y+=st2.top();
            st2.pop();
        }
        cout<<x<<" "<<y<<endl;
        
        return x==y;
        
    }
};