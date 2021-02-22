class Solution {
public:
    bool halvesAreAlike(string s) 
    {
        int n=s.size(),v1=0,v2=0;
        string s1=s.substr(0,n/2);
        string s2=s.substr(n/2,n/2);
        for(auto x: s1)
            if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'||x=='A'||x=='E'||x=='I'||x=='O'||x=='U')
                v1++;
        for(auto x: s2)
            if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'||x=='A'||x=='E'||x=='I'||x=='O'||x=='U')
                v2++;
        return v1==v2;
    }
};