class Solution {
public:
    bool checkZeroOnes(string s) 
    {
        int maxOnes=0,maxZeros=0;
        int n=s.size();
        for(int i=0; i<n; i++)
        {
            int j=i, ct=0;
            if(s[i]=='0')
            {
                while(j<n and s[j]=='0')
                {
                    ct++;
                    j++;
                }
                i=j-1;
                maxZeros=max(maxZeros,ct);
            }
            else
            {
                while(j<n and s[j]=='1')
                {
                    ct++;
                    j++;
                }
                i=j-1;
                maxOnes=max(maxOnes,ct);
            }
        }
        return maxOnes>maxZeros;
    }
};