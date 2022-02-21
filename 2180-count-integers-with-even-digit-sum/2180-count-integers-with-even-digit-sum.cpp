class Solution {
public:
    int countEven(int n) 
    {
        int ct=0;
        auto digSum = [](int x)
        {
            int sum=0;
            while(x>0)
            {
                sum+=x%10;
                x/=10;
            }
            return sum;
        };
        
        for(int i=2; i<=n; i++)
        {
            if(digSum(i)%2==0)
                ct++;
        }
        return ct;
    }
};