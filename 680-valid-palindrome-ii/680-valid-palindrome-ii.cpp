class Solution {
public:
    bool check(string s)
    {
        string t = s;
        reverse(t.begin(),t.end());
        return t==s;
    }
    
    bool validPalindrome(string s) 
    {
        int n=s.size();
        int i=0 , j=n-1;
        while(i<=j)
        {
            if(s[i]==s[j])
                i++,j--;
            else
            {
                string s1 = s.substr(i+1,j-i);
                string s2 = s.substr(i,j-i);
                // cout<<s1<<" "<<s2<<endl;
                bool ch1 = check(s1);
                bool ch2 = check(s2);
                if(!ch1 and !ch2)
                    return false;
                else
                    return true;
                    
            }
        }
        return true;
    }
};