class Solution {
public:
    int uniqueLetterString(string s) 
    {
        int n=s.size() , ans=0;
        for(int i=0; i<n; i++)
        {
            int lt=1,rt=1;
            int x=i-1,y=i+1;
            while(x>=0 and s[x]!=s[i])
            {
                x--;
                lt++;
            }
            while(y<n and s[y]!=s[i])
            {
                y++;
                rt++;
            }
            ans+=(lt*rt);
        }
        return ans;
        
    }
};