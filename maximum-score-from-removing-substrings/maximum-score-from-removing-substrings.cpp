class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int ans;
    void remove(string&s, string rem, int points)
    {
        int n=s.size();
        int write=0;
        for(int read=0; read<n; read++)
        {
            s[write++]=s[read];
            if(write>=2&&s[write-1]==rem[1]&&s[write-2]==rem[0])
            {
                write-=2;
                ans+=points;
            }
        }
        s.resize(write);
    }
    int maximumGain(string s, int x, int y) 
    {
        string a="ab" , b="ba";
        ans=0;
        if(x<y)
        {
            swap(x,y);
            swap(a,b);
        }
        remove(s,a,x);
        remove(s,b,y);
        return ans;
    }
};
