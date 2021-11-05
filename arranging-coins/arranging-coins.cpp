class Solution {
public:
    int arrangeCoins(int n) 
    {
        long long x=1+8*(long long)n;
        long long z=sqrt(x);
        int k=(-1+z)/2;
        return k;
    }
};