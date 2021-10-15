class Solution {
public:
    int countSubstrings(string s, string t) 
    {
        int n=s.size() , m=t.size();
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(s[i]!=t[j])
                {
                    int p1=i-1,p2=j-1;
                    int left=0,right=0;
                    while(p1>=0 and p2>=0 and s[p1]==t[p2])
                    {
                        left++;
                        p1--;
                        p2--;
                    }
                    
                    int q1=i+1,q2=j+1;
                    while(q1<n and q2<m and s[q1]==t[q2])
                    {
                        right++;
                        q1++;
                        q2++;
                    }
                    
                    ans+=(left+1)*(right+1);
                }
            }
        }
        
        return ans;
        
    }
};