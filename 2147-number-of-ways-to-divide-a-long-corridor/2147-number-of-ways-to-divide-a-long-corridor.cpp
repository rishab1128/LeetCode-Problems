const int mod=1e9+7;

class Solution {
public:
    int numberOfWays(string s) 
    {
        long long n=s.size() , ct=0, p=0, sc=0, ans=1;
        
        for(auto x: s)
        {
            if(x=='S')
                sc++;
        }
        if(sc==0 || sc%2)
            return 0;
        
        for(int i=0; i<n; i++)
        {
            if(s[i]=='S' and ct<2){
                ct++;
                continue;
            }
            while(i<n and ct==2 and s[i]=='P')
            {
                p++;
                i++;
                if(i==n)
                {
                    ans*=1;
                    return ans;
                }
            }
            if(ct==2)
            {
                // cout<<p+1<<endl;
                ans*=(p+1);
                ans%=mod;
                ct=0;
                p=0;
                i--;
            }
            
        }
        
        return ans;
        
    }
};