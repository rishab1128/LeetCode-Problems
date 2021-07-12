class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if(needle.size()==0)
            return 0;
        int n=haystack.size();
        int m=needle.size();
        for(int i=0; i<=n-m; i++)
        {
            string t=haystack.substr(i,m);
            if(t==needle)
                return i;
        }
        return -1;
        
    }
};