class Solution {
public:
    int maxPower(string s) 
    {
        int n=s.size();
        int maxi=0;
        for(int i=0; i<n; i++)
        {
            char ch=s[i];
            int ct=0;
            while(i<n and ch==s[i])
            {
                ct++;
                i++;
            }
            maxi=max(maxi,ct);
            i--;
        }
        return maxi;
    }
};