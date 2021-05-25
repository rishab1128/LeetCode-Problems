class Solution {
public:
    string makeGood(string s) 
    {
        int n=s.size();
        if(n<=1)
            return s;
        string t="";
        for(int i=0; i<n; i++)
        {
            char z=t.back();
            //cout<<z<<endl;
            if(islower(s[i]) and isupper(z) and tolower(s[i])==tolower(z))
                t.pop_back();
            else if(islower(z) and isupper(s[i]) and tolower(s[i])==tolower(z))
                t.pop_back();
            else
                t+=s[i];
        }
        
        return t;
        
    }
};