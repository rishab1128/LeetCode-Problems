class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) 
    {
        int n=shifts.size();
        vector<long long>suff(n);
        suff[n-1]=shifts[n-1];
        for(int i=n-2; i>=0; i--)
            suff[i]=suff[i+1]+shifts[i];
        
        string ans=s;
        for(int i=0; i<n; i++)
        {
            int x=ans[i]-'a';
            char tmp=(x+suff[i])%26+'a';
            ans[i]=tmp;
        }
        return ans;
        
    }
};