class Solution {
public:
    bool checkValidString(string s) 
    {
        int n =s.size();
        int op = 0 , cl = 0;
        stack<int> st;
        
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
                op++;
            else if(s[i]==')') 
                cl++;
            else
                st.push(i);
            
            while(cl>op && !st.empty()){
                s[st.top()] = '(';
                st.pop();
                op++;
            }
            
            if(cl>op) 
                return false;
        }
        
        if(op==cl) 
            return true;
    
        int stars = 0;
        op = 0;
        cl = 0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='(')
                op++;
            else if(s[i]==')') 
                cl++;
            else
                stars++;
            
            while(op>cl && stars>0){
                cl++;
                stars--;
            }
            if(op>cl) 
                return false;
        }
        return true;
    }
};