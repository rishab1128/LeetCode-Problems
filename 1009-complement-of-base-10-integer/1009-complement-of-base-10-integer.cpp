class Solution {
public:
    int bitwiseComplement(int n)
    {
        if(n==0)
            return 1;
        int ans=0;
        int dig=log2(n);
        for(int i=0; i<dig; i++)
        {
            int num=(1<<i);
            int x=n&num;
            if(x==0)
                ans+=num;
        }
        return ans;
        
    }
};