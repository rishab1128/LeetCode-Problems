class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int numberOfMatches(int n) 
    {
        int ct=0;
        while(n>1)
        {
            ct+=n/2;
            if(n%2)
                n=(n/2)+1;
            else
                n=n/2;
        }
        return ct;
        
    }
};
