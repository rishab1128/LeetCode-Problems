class Solution {
public:
    
    string say(string s)
    {
        int n = s.size();
        string ans = "";
        for(int i=0; i<n; i++)
        {
            int j=i+1 , freq=1;
            while(j<n and s[i]==s[j])
            {
                j++;
                freq++;
            }
            string s1 = to_string(freq);
            string s2 = "";
            s2+=s[i];
            ans+=s1+s2;
            i=j-1;
        }
        return ans;
    }
    
    string countAndSay(int n) 
    {
        if(n==1)
            return "1";
        string smallerString = countAndSay(n-1);
        string ans = say(smallerString);
        return ans;
    }
};