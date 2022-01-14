class Solution {
public:
    int myAtoi(string s) 
    {
        int ans=0;
        int n=s.size();
        //cout<<n<<endl;
        int minus=0 ,  step2=0;
        for(int i=0; i<n; i++)
        {
            if(isspace(s[i]) and !step2)
                continue;
            
            else if(s[i]=='-' and !step2)
            {
                minus=1;
                step2=1;
                continue;
            }
            
            else if(s[i]=='+' and !step2)
            {
                step2=1;
                continue;
            }
            
            else if(isalpha(s[i]) || isspace(s[i]) || s[i]=='-' || s[i]=='+' || s[i]=='.' )
                break;
            
            else if(isdigit(s[i]))
            {
                if(ans>INT_MAX/10 || (ans==INT_MAX/10 && (s[i]-'0')>7))
                {
                    ans=INT_MAX;
                    break;
                }
                if(ans<INT_MIN/10 || (ans==INT_MIN/10 && (s[i]-'0')>8))
                {
                    ans=INT_MIN;
                    break;
                }
                
                
                if(minus)
                {
                    ans=ans*10-(s[i]-'0');
                }
                else
                {
                    ans=ans*10+(s[i]-'0');
                }
                //cout<<ans<<endl;
                    
                if(i+1<n and (isalpha(s[i+1]) || isspace(s[i+1]) || s[i+1]=='-' || s[i+1]=='+' || s[i+1]=='.'))
                    break;
            }
                
        }
        
        
        return ans;
    }
};