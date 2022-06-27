class Solution {
public:
    int minPartitions(string s) 
    {
        int n=s.size();
        int maxi=0;
        for(int i=0; i<n; i++)
        {
            maxi=max(maxi,s[i]-'0');
        }
        return maxi;
    }
};