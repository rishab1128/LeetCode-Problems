class Solution {
public:
    //Using Divide and Conquer strategy
    
    int dc(string s , int start, int end)
    {
        int bal=0, ans=0;
        for(int i=start; i<=end; i++)
        {
            if(s[i]=='(')
                bal++;
            else
                bal--;
            
            if(bal==0)
            {
                if(i-start==1)
                    ans++;
                else
                    ans+=2*dc(s,start+1,i-1);
                
                start=i+1;
            }
            
        }
        return ans;
        
    }
    
    int scoreOfParentheses(string s) 
    {
        int n=s.size();
        int ans=dc(s,0,n-1);
        return ans;
    }
};