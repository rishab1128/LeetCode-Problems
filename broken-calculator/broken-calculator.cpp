class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int brokenCalc(int x, int y) 
    {
        if(x>=y)
            return x-y;
        int ct=0;
        while(y!=x)
        {
            if(y<x)
                y+=1;
            else if(y%2==1)
                y+=1;
            else if(y%2==0)
                y/=2;
            ct++;
        }
        return ct;
    }
};