class Solution {
public:
    int minOperations(int n) 
    {
        int lo=1,hi=2*n-1,ans=0;
        while(lo<hi)
        {
            int diff=hi-lo;
            ans+=(diff/2);
            hi-=2;
            lo+=2;
        }
        return ans;
    }
};
