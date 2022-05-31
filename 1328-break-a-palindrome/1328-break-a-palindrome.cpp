class Solution {
public:
    string breakPalindrome(string palin) 
    {
        int n=palin.size();
        if(n==1)
            return "";
        
        int ct=0;
        for(auto x: palin)
        {
                if(x=='a')
                    ct++;
        }
        
        if(n%2 and ct==n-1)
        {
            palin[n-1]='b';
            return palin;
        }
        
        bool flag=0;
        for(int i=0; i<n; i++)
        {
            if(palin[i]!='a')
            {
                palin[i]='a';
                flag=1;
                break;
            }
        }
        
        if(!flag)
            palin[n-1]='b';
        
        return palin;
    }
};