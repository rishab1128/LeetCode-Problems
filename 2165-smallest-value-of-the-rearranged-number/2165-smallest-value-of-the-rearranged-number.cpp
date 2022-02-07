using ll=long long;
class Solution {
public:
    long long smallestNumber(long long num) 
    {
        if(num==0)
            return 0;
        
        ll n=abs(num) , res=-1;
        
        string s=to_string(n);
        sort(s.begin(),s.end());
        
        if(num>0)
        {
            ll freq=0 , idx=-1;
            for(int i=0; i<s.size(); i++)
            {
                if(s[i]=='0')
                    freq++;
                else
                {
                    idx=i;
                    break;
                }
            }
            
            string ans="";
            ans+=s[idx];
            for(int i=0; i<freq; i++)
                ans+='0';
            for(int i=idx+1; i<s.size(); i++)
                ans+=s[i];
            
            res=stoll(ans);
        }
        else
        {
            reverse(s.begin(),s.end());
            // cout<<s<<endl;
            res=stoll(s);
            res*=-1;
        }
        
        return res;
        
    }
};